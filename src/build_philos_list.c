/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philos_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:35:23 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 21:31:49 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int build_and_assign_forks(t_general *data)
{
	int i;

	data->forks_locks = malloc(sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->forks_locks)
	{
		//liberar array de filosy demas cosaas que tuviere, puedo hacerlo aqui o fuera de la funcion
		return (0); //pues saldria limpio
	}
	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i]->right_fork = &data->forks_locks[i];
		if (i > 0)
			data->philos[i]->left_fork = data->philos[i - 1]->right_fork;
		data->philos[i]->data = data;
		i++;
	}
	data->philos[0]->left_fork =  data->philos[i - 1]->right_fork;
	data->philos[i] = NULL;
	return (1);
}

int build_philos_array (t_general *data)
{
	t_philo *philos;
	int i;

	
	philos = malloc(sizeof(t_philo) * (data->philo_num + 1));
	if (!philos)
		return (0);
	data->first_philo = philo;
	i = 0;
	while (i < data->philo_num)
	{
		philos[i]->id = i + 1;
		philos[i]->data = data;
		philos[i]->dead_status = 0;
		i++;
	}
	philo[i] = NULL;
	return (1);
}


//dividir en una funcion de init forks