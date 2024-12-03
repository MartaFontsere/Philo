/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:41:12 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/03 00:03:44 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//REVIAR LAS TRES PRIMERAS FUNCIONES, HABER PUESTO LOS NOMBRES CORRECTOS


int init_dead_status_array (t_general *data)
{
	int i;

	i = 0;
	data->dead_status_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!data->dead_status_array)
	{
		write(2, "ABORT: Malloc Failed\n", 21);
		free_since_num_meals_function (data);
		return (0);
	}
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->dead_status_array[i], NULL)!= 0)
		{
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			free_since_num_meals_function (data);
			while (--i >= 0)
				pthread_mutex_destroy(&data->dead_status_array[i]);
			free (data->dead_status_array);
			return (0);
		}
		i++;
	}
	return (1);
}

int init_num_meals_array (t_general *data)
{
	int i;

	i = 0;
	data->num_meals_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!data->num_meals_array)
	{
		write(2, "ABORT: Malloc Failed\n", 21);
		free_since_last_meal_function (data);
		return (0);
	}
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->num_meals_array[i], NULL)!= 0)
		{
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			
			free_since_last_meal_function (data);
			while (--i >= 0)
				pthread_mutex_destroy(&data->num_meals_array[i]);
			free (data->num_meals_array);
			//liberar mutex de num_meals_array, desde donde ha fallado hacia atras;
			return (0);
		}
		i++;
	}
	return (1);
}

int init_last_meal_array (t_general *data)
{
	int i;

	i = 0;
	data->last_meal_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!data->last_meal_array)
	{
		write(2, "ABORT: Malloc Failed\n", 21);
		free_3_last_mutex (data);
		return (0);
	}
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->last_meal_array[i], NULL)!= 0)
		{
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			while (--i >= 0)
				pthread_mutex_destroy(&data->last_meal_array[i]);
			//liberar mutex de philo status array, desde donde ha fallado hacia atras;
			free (data->last_meal_array);
			free_3_last_mutex (data);
			return (0);
		}
		i++;
	}
	return (1);
}

int init_data_struct (t_general *data)
	{
		data->philos = NULL;
		data->stop_simulation = 0;
		if (pthread_mutex_init(&data->start_lock, NULL)!= 0)
		{
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			return (0);
		}
		if (pthread_mutex_init(&data->write_lock, NULL)!= 0)
		{
			pthread_mutex_destroy(&data->start_lock);
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			return (0);
		}
		if (pthread_mutex_init(&data->life_checker_lock, NULL)!= 0)
		{
			free_2_last_mutex (data);
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			return (0);
		}
		data->t_start = 0;
		data->num_threads = 0;
		if (init_last_meal_array (data) == 0)
			return (0);
		if (init_num_meals_array (data) == 0)
			return (0);
		if (init_dead_status_array (data) == 0)
			return (0);
		return (1);
	}
	
	//cada fiosofo tiene un tenedor, y tendra que coger el suyo y el del siguiente. por lo tanto tengo que inicializar mi tenedor y cuando este 
