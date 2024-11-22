/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:40:25 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/19 03:19:56 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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