/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:36:46 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 23:40:08 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_data_mutex (t_general *data)
{
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->life_checker_lock);
}

void free_arrays(t_general *data)
{
	free_data_mutex (data);
	free (data->philos);
	data->philos = NULL;
	free (data->forks_array);
	data->forks_array = NULL;
}

void free_all_info(t_general *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks_array[i]);
		i++;
	}
	free_arrays (data);
}

