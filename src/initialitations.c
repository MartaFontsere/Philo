/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialitations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:59 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 22:16:01 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init data struct
int init_data_struct (t_general *data)
{
	data->dead_flag = 0;
	// philos = NULL;
	// data->first_philo = philos;// Es un puntero al puntero que señala la primera posicion de la lista de filosofos
	data->first_philo = NULL;
	if (pthread_mutex_init(&program->write_lock, NULL)!= 0)
		return (0);
	if (pthread_mutex_init(&program->dead_lock, NULL)!= 0)
		return (0);
	if (pthread_mutex_init(&program->eat_lock, NULL)!= 0)
		return (0);
	return (1);
}
//cada fiosofo tiene un tenedor, y tendra que coger el suyo y el del siguiente. por lo tanto tengo que inicializar mi tenedor y cuando este 
