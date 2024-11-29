/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialitations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:59 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/28 21:36:27 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init data struct
int init_data_struct (t_general *data)
{
	data->philos = NULL;
	data->dead_flag = 0;
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
	// if (pthread_mutex_init(&program->eat_lock, NULL)!= 0)
	// 	return (0);
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