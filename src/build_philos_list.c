/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philos_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:35:23 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 03:46:40 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void	put_new_list_philo_node(t_general *data, t_philo *new_philo)
// {
// 	t_philo	*tmp_philo;

// 	if (!data->first_philo)
// 	{
// 		data->first_philo = new_philo;
// 		data->first_philo->next = NULL;
// 	}
// 	else
// 	{
// 		tmp_philo = data->first_philo;
// 		while (tmp_philo && tmp_philo->next)
// 			tmp_philo = tmp_philo->next;
// 		tmp_philo->next = new_philo;
// 		philo->next = NULL;
// 	}
// }

// t_philo create_philos (void)
// {
// 	t_philo *new_philo;

// 	new_philo = malloc(sizeof(t_philo) * 1);
// 	if (!new_philo)
// 		return (NULL);
// 	return (new_philo);
// }

// int build_philos_array (t_general *data)
// {
// 	t_philo *new_philo;
// 	int i;

// 	i = 1;
// 	while (i <= data->philo_num)
// 	{
// 		new_philo = create_philos ()
// 		if (!new_philo)
// 		{
// 			//free lista de philos hasta ahora;
// 			return (0);
// 		} 
// 		//rellenar
// 		new_philo->id = i;
// 		new_philo->data = data;
// 		put_new_list_philo_node (data, new_philo);
// 		i++;
// 	}
// 	return (1);
// }


int build_philos_array (t_general *data)
{
	t_philo *philos;
	int i;

	
	philos = malloc(sizeof(t_philo) * (data->philo_num + 1));
	if (!philos)
		return (0);
	i = 0;
	while (i < data->philo_num)
	{
		philos->id = i + 1;
		if (pthread_mutex_init(&philos->tenedor_propio, NULL) != 0)
		{
			free(philos);
			return (0);
		}
		if (i > 0)
			philos->tenedor_externo = &data->first_philo[i - 1]->tenedor_propio;
		philos->data = data;
		i++;
	}
	data->first_philo[0]->tenedor_externo =  &data->first_philo[i - 1]->tenedor_propio;;
	philo[i] = NULL;
	return (1);
}


//dividir en una funcion de init forks