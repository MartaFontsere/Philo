	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   initialitations.c                                  :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2024/11/15 01:19:59 by mfontser          #+#    #+#             */
	/*   Updated: 2024/11/29 19:40:23 by mfontser         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "philo.h"

	//init data struct

//REVIAR LAS TRES PRIMERAS FUNCIONES, HABER PUESTO LOS NOMBRES CORRECTOS

	int init_last_meal_array (t_general *data)
	{
		int i;

		data->last_meal_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
		if (!data->last_meal_array)
		{
			write(2, "ABORT: Malloc Failed\n", 21);
			pthread_mutex_destroy(&data->start_lock);
			pthread_mutex_destroy(&data->write_lock);
			return (0);
		}
		i = 0;
		while (i < data->philo_num)
		{
			if (pthread_mutex_init(&data->last_meal_array[i], NULL)!= 0)
			{
				write(2, "ABORT: Error while creatin a Mutex\n", 35);
				free (data->last_meal_array);
				//liberar mutex de philo status array, desde donde ha fallado hacia atras;
				pthread_mutex_destroy(&data->start_lock);
				pthread_mutex_destroy(&data->write_lock);
				return (0);
			}
			i++;
		}
		return (1);

	}

	int init_num_meals_array (t_general *data)
	{
		int i;

		data->num_meals_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
		if (!data->num_meals_array)
		{
			write(2, "ABORT: Malloc Failed\n", 21);
			free (data->last_meal_array);
			pthread_mutex_destroy(&data->start_lock);
			pthread_mutex_destroy(&data->write_lock);
			return (0);
		}
		i = 0;
		while (i < data->philo_num)
		{
			if (pthread_mutex_init(&data->num_meals_array[i], NULL)!= 0)
			{
				write(2, "ABORT: Error while creatin a Mutex\n", 35);
				free (data->num_meals_array);
				free (data->last_meal_array);
				//liberar mutex de num_meals_array, desde donde ha fallado hacia atras;
				pthread_mutex_destroy(&data->start_lock);
				pthread_mutex_destroy(&data->write_lock);
				return (0);
			}
			i++;
		}
		return (1);
	}

	int init_dead_status_array (t_general *data)
	{
		int i;

		data->dead_status_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
		if (!data->dead_status_array)
		{
			write(2, "ABORT: Malloc Failed\n", 21);
			free (data->num_meals_array);
			free (data->last_meal_array);
			pthread_mutex_destroy(&data->start_lock);
			pthread_mutex_destroy(&data->write_lock);
			return (0);
		}
		i = 0;
		while (i < data->philo_num)
		{
			if (pthread_mutex_init(&data->dead_status_array[i], NULL)!= 0)
			{
				write(2, "ABORT: Error while creatin a Mutex\n", 35);
				free (data->dead_status_array);
				free (data->num_meals_array);
				free (data->last_meal_array);
				//liberar mutex de dead_status_array, desde donde ha fallado hacia atras;
				pthread_mutex_destroy(&data->start_lock);
				pthread_mutex_destroy(&data->write_lock);
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
		// philos = NULL;
		// data->first_philo = philos;// Es un puntero al puntero que señala la primera posicion de la lista de filosofos
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
		if (pthread_mutex_init(&data->dead_lock, NULL)!= 0)
		{
			pthread_mutex_destroy(&data->start_lock);
			pthread_mutex_destroy(&data->write_lock);
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			return (0);
		}
		data->t_start = 0;
		if (init_last_meal_array (data))
			return (0);
		if (init_num_meals_array (data))
			return (0);
		if (init_dead_status_array (data))
			return (0);
		return (1);
	}
	//cada fiosofo tiene un tenedor, y tendra que coger el suyo y el del siguiente. por lo tanto tengo que inicializar mi tenedor y cuando este 

	int init_philos_struct(t_general *data)
	{
		int i;

		i = 0;
		while (i < data->philo_num)
		{
			data->philos[i].right_fork = &data->forks_array[i]; //philos[i] no es un puntero, es un philo en concreto, por eso luego le sigue un punto
			if (i > 0)
				data->philos[i].left_fork = data->philos[i - 1].right_fork;
			data->philos[i].dead_status = 0;
			data->philos[i].data = data;
			i++;
		}
		data->philos[0].left_fork =  data->philos[i - 1].right_fork;
		return (1);
	}