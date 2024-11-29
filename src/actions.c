/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:38:28 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 23:48:17 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


int	take_forks(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(philo->right_fork);
	status = print_state(philo->table, philo, TAKEN_FORK_STATE);
	if (status == STOPPED || philo->right_fork == philo->left_fork)
		return (pthread_mutex_unlock(philo->right_fork), 0);
	pthread_mutex_lock(philo->left_fork);
	status = print_state(philo->table, philo, TAKEN_FORK_STATE);
	if (status == STOPPED)
		return (unlock_forks(philo), 0);
	return (status);
}

