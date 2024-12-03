/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:40:25 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/03 02:32:23 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_extreme_cases(t_general *data)
{
	if (data->philo_num == 0 || data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: no parameter can be 0\n", 29);
		write(2, END, ft_strlen(END));
		return (0);
	}
	if (data->philo_num > 200)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: Too many philosophers, ", 30);
		write(2, "not enough spaghetti for everyone\n", 34);
		write(2, END, ft_strlen(END));
		return (0);
	}
	return (1);
}

int	params_conversion_to_int(t_general *data, char **argv)
{
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_eats_each_philo = ft_atoi(argv[5]);
	else
		data->num_eats_each_philo = -1;
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

int	check_signs(char **argv, int i, int *j)
{
	if (argv[i][*j] == '-')
	{
		error_negative_sign();
		return (0);
	}
	if (argv[i][*j] == '+')
	{
		if (argv[i][*j + 1] == '\0')
		{
			error_positive_sign();
			return (0);
		}
		(*j)++;
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
			error_empty_string();
			return (0);
		}
		if (check_signs(argv, i, &j) == 0)
			return (0);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				error_non_numbers_found();
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	params_are_valids(t_general *data, char **argv)
{
	if (check_valid_format(argv) == 0)
		return (0);
	if (check_size_int(argv) == 0)
		return (0);
	params_conversion_to_int(data, argv);
	if (check_extreme_cases(data) == 0)
		return (0);
	return (1);
}
