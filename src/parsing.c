/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:40:25 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/23 19:15:16 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	prepare_params(t_general *data, char **argv)
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

int	check_size_int(char **argv)
{
	int		i;
	char	*to_check;

	i = 1;
	while (argv[i])
	{
		to_check = argv[i];
		if (argv[i][0] == '+')
			to_check++;
		while (*to_check == '0' && to_check[1] != '\0')
			to_check++;
		if (ft_strlen(to_check) > 10)
			return (0);
		else if (ft_strlen(to_check) == 10)
		{
			if (argv[i][0] != '-' && ft_strncmp(MAX_INT, to_check, 10) < 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_format(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '\0')
		{
			error_empty_string ();
			return (0);
		}
		if (argv[i][j] == '-')
		{
			error_negative_sign(); 
			return (0);
		}

		if (argv[i][j] == '+')
		{
			if (argv[i][j + 1] == '\0')
			{
				error_positive_sign();
				return (0);
			}
			j++;
		}
		while (argv[i][j] != '\0')
		{
			if (ft_isspace(argv[i][j]) == 1)
			{
				error_space_after_sign(); 
				return (0);
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				error_chars_found(); 
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	params_are_valids(char **argv)
{
	if (check_valid_format(argv) == 0)
		return (0);
	if (check_size_int(argv) == 0)
		return (0);
	return (1);
}