/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:08:12 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 23:37:34 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_current_time(void)
{
	struct timeval		tmp;
	unsigned int		current_time;

	gettimeofday(&tmp, NULL);
	current_time = (unsigned int)tmp.tv_sec * 1000 + tmp.tv_usec * 0.001;
	return (current_time);
}

unsigned int	get_simulation_time(t_general *data)
{
	return (get_current_time() - data->t_start);
}

// int	comprove_death(t_simulation *sim)
// {
// 	int	is_n_death;

// 	is_n_death = 1;
// 	pthread_mutex_lock(&sim->check_flag);
// 	if (sim->flag_death == 1)
// 		is_n_death = 0;
// 	pthread_mutex_unlock(&sim->check_flag);
// 	return (is_n_death);
// }