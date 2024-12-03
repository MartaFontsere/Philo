/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialitations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:59 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/02 22:07:22 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init data struct

int initialitations (t_general *data)
{
	if (init_data_struct(data) == 0)
		return (0);
	if (build_philos_and_forks(data) == 0)
		return (0);
	init_philos_struct(data);
	return (1);
}
