/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:41:57 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/03 00:21:04 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int check_simulation_state (t_philo *philo)
{
	pthread_mutex_lock (&philo->data->life_checker_lock);
	if (!philo->data->stop_simulation)
	{
		pthread_mutex_unlock (&philo->data->life_checker_lock); // Es mas optimo asi que crear una variable, igualarla a 1 o 0, y hacer el unlock al final y retornar esa variable. Asi no espera hasta el final para mandar la info (no tarda tanto), no usas una variable que no necesitas (no ocupas memoria, el ordenador gasta tiempo en declarar y asignarle valor). Y es mas rapido si hay un solo if, no tiene que meterse en el if else a comprobar. Igual son nanosegundos que tarda, pero es mas optimo si la tengo que llamar muchas veces, como es el caso.
		return (RUNNING);
	}
	pthread_mutex_unlock (&philo->data->life_checker_lock);
	return (STOPPED);
}


int	all_meals_eaten(t_general *data, int num_of_philos_eaten_enough)
{
	if (data->philo_num == num_of_philos_eaten_enough)
	{
		pthread_mutex_lock(&data->life_checker_lock);
		data->stop_simulation = 1;
		pthread_mutex_unlock(&data->life_checker_lock);
		pthread_mutex_lock(&data->write_lock);
		printf(RED"We are full of eating so much spaghetti 🥴💥\n"END);
		pthread_mutex_unlock(&data->write_lock);
		return (1);
	}
	return (0);
}

void	kill_philo(t_general *data, t_philo *philo)
{
	unsigned int	current_time;

	current_time = get_simulation_time(data);
	pthread_mutex_lock(&data->life_checker_lock);
	data->stop_simulation = 1;
	pthread_mutex_unlock(&data->life_checker_lock);
	pthread_mutex_lock(&data->write_lock);
	printf(RED"[%d]  %d %s\n"END, current_time, philo->id, DIED);
	pthread_mutex_unlock(&data->write_lock);
}

void	supervise_simulation(t_general *data)
{
	int	i;
	int	num_of_philos_eaten_enough;

	i = 0;
	num_of_philos_eaten_enough = 0;
	while (!data->stop_simulation)
	{
		//usleep (1000); // SI?????
		if (i == data->philo_num) //Reseteo para que vaya dando vueltas entre los filos creados y no se dupliquen resultados
		{
			i = 0;
			num_of_philos_eaten_enough = 0;
		}
		
		if (data->num_eats_each_philo != -1)
		{
			pthread_mutex_lock(data->philos[i].n_meals);
			if (data->philos[i].num_meals >= data->num_eats_each_philo)
				num_of_philos_eaten_enough++;
			pthread_mutex_unlock(data->philos[i].n_meals);


			if (all_meals_eaten(data, num_of_philos_eaten_enough))
			{
				//printf("hola\n");
				break ;
			}
		}

		pthread_mutex_lock(data->philos[i].l_meal);
		if (get_simulation_time(data) - data->philos[i].last_meal >= data->time_to_die)
			kill_philo(data, &data->philos[i]);
		pthread_mutex_unlock(data->philos[i].l_meal);
		i++;
	}
}


