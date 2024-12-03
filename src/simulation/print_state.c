/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:28:11 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/02 17:16:16 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	print_state(t_philo *philo, char *state)
{
	char *color;

	color = philo->color;
	pthread_mutex_lock(&philo->data->write_lock);
	if (check_simulation_state(philo) == RUNNING)
	{
		printf("%s[%d]  %d %s\n"END, color, get_simulation_time(philo->data), philo->id, state);

		pthread_mutex_unlock(&philo->data->write_lock);
		return (RUNNING);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	return (STOPPED);
}


/*
Cualquier cambio de estado de un filósofo debe tener el siguiente formato:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos
y X con el numero del filósofo.
*/