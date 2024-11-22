/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialitations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:59 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/21 01:32:11 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_data_values(t_general *data, char **argv)
{
	printf ("Data values:\n");
	data->philo_num = ft_atoi(argv[1]);
	data->to_die = ft_atoi(argv[2]);
	data->to_eat = ft_atoi(argv[3]);
	data->to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_eats_each_philo = ft_atoi(argv[5]);
	printf ("%d\n", data->philo_num);
	printf ("%d\n", data->to_die);
	printf ("%d\n", data->to_eat);
	printf ("%d\n", data->to_sleep);
	if (argv[5])
		printf ("%d\n", data->num_eats_each_philo);
	if (data->philo_num == 0 || data->to_die == 0 || data->to_eat == 0 || data->to_sleep == 0)
	{
		write (2, "Error: no parameter can be 0\n", 29);
		return (0);
	}
	if (data->philo_num > 200)
	{
		write (2, "Error: Too many philosophers, not enough spaghetti for everyone\n", 64);
		return (0);
	}
	return (1);
}
