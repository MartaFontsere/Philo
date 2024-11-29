/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:28:11 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 23:52:48 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	print_state(/*t_table *table, t_philo *philo, char *state*/)
{
	unsigned int	current_time;

	current_time = get_time();
	pthread_mutex_lock(&philo->data->write_lock);
	if (check_simulation_state(philo) == RUNNING)
	{
		printf("[%d] %d %s", current_time - philo->data->t_start, philo->num, state); // WRITE
		pthread_mutex_unlock(&table->printer);
		return (1);
	}
	pthread_mutex_unlock(&table->printer);
	return (0);
}
