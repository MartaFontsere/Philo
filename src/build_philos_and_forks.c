/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philos_and_forks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:35:23 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 22:01:05 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int build_forks_array(t_general *data)
{
	int i;

	data->forks_array = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!data->forks_array)
	{
		write(2, "ABORT: Malloc Failed\n", 21);
		//REVISAR
		free_data_mutex (data);
		free (data->philos); //liberar array de filos y demas cosaas que tuviere, puedo hacerlo aqui o fuera de la funcion
		return (0); //pues saldria limpio
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->forks_array[i], NULL)!= 0)
		{
			//REVISAR
			write(2, "ABORT: Error while creatin a Mutex\n", 35);
			//liberar mutex de philo status array, desde donde ha fallado hacia atras;
			//faltan liberar cosas;
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

	philos = malloc(sizeof(t_philo) * (data->philo_num)); // no hago + 1 porque solo puedo igualar a null final si es un puntero, pero es tipo t philo
	if (!philos)
	{
		//REVISAR
		write(2, "ABORT: Malloc Failed\n", 21);
		free_data_mutex (data);
		return (0);
	}
	data->philos = philos;
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
