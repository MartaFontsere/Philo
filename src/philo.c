/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:07:55 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/21 02:32:16 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_general		data;
	t_philo			philos[PHILO_MAX];

	if (argc > 6 || argc < 5)
	{
		wrong_number_of_parameters();
		return (1);
	}
	
	//parsing
	if (params_are_valids(argv) == 0)
		return (1);

	//init
	if (init_data_values(&data,argv) == 0) // cambiar nombre a la funcion
		return (1);

	//init data struct
	void init_data_struct (t_general		data, t_philo			philos)
	{
		data->dead_flag = 0;
		data->philos = philos;
		pthread_mutex_init(&program->write_lock, NULL);
		pthread_mutex_init(&program->dead_lock, NULL);
		pthread_mutex_init(&program->meal_lock, NULL);
	}





	return (0);
}