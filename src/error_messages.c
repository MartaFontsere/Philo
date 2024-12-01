/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:27:47 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 18:37:24 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void error_space_after_sign()
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error: The formatting is invalid, ", 34);
	write(2, "there is a space after a signChars have been found\n", 51);
	write(2, END, ft_strlen(END));
}

void error_chars_found()
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error: Chars have been found, ", 30);
	write(2, "only numbers accepted\n", 22);
	write(2, END, ft_strlen(END));
}

void error_positive_sign()
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error: There is only one plus sign, ", 36);
	write(2, "incorrect format\n", 17);
	write(2, END, ft_strlen(END));
}

void error_negative_sign()
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error: There is a negative sign, ", 33);
	write(2, "but negative numbers are not accepted\n", 38);
	write(2, END, ft_strlen(END));
}

void error_empty_string()
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error: There is an empty string\n", 32);
	write(2, END, ft_strlen(END));
}

void wrong_number_of_parameters()
{
	write(2, RED, ft_strlen(RED));
	write(2, "To run the program you need the following parameters:\n", 54);
	write(2, "  * ./philo\n", 12);
	write(2, "  * number_of_philosophers\n", 27);
	write(2, "  * time_to_die\n", 16);
	write(2, "  * time_to_eat\n", 16);
	write(2, "  * time_to_sleep\n", 18);
	write(2, "  * number_of_times_each_philosopher_must_eat (optional)\n", 57);
	write(2, "\nTry again ✌️\n", 18);
	write(2, END, ft_strlen(END));
}
