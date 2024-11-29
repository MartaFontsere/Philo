/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philos_and_forks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:35:23 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/28 20:58:29 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int build_forks_array(t_general *data)
{
	int i;

	data->forks_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->forks_array)
	{
		write(2, "ABORT: Malloc Failed\n", 21);
		free_data_mutex (data);
		free (data->philos); //liberar array de filos y demas cosaas que tuviere, puedo hacerlo aqui o fuera de la funcion
		return (0); //pues saldria limpio
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->forks_array[i], NULL)!= 0)
		{
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			free_arrays (data);
			return (0);
		}
		i++;
	}
	return (1);
}


int build_philos_array (t_general *data)
{
	t_philo *philos;
	int i;

	philos = malloc(sizeof(t_philo) * (data->philo_num + 1));
	if (!philos)
	{
		write(2, "malloc error\n", 13);
		free_data_mutex (data);
		return (0);
	}
	data->philos = philos;
	i = 0;
	while (i < data->philo_num)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		//philos[i].dead_status = 0;
		philos[i].num_eats = 0;
		philos[i].last_eat = 0;
		i++;
	}
	// philos[i] = NULL;
	return (1);
}

int build_philos_and_forks(t_general *data)
{
	if (build_philos_array (data) == 0)
		return (0);
	if (build_forks_array(data) == 0)
		return (0);
	return (1);
}
