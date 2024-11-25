/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:07:55 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 04:14:14 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Mejor manera para empezar, hacer un archivo de prueba en el que creo threads, veo que hacen y luego crear mutex y ver como interactuan. Asi aprendes la mecanica de los nuevos conceptos

int main (int argc, char **argv)
{
	t_general		data;

	if (argc > 6 || argc < 5)
	{
		wrong_number_of_parameters();
		return (1);
	}
	
	//parsing
	if (params_are_valids(argv) == 0)
		return (1);
	if (prepare_params(&data, argv) == 0)
		return (1);
	//init data struct
	if (init_data_struct(&data) == 0)
		return (1);
	if (build_philos_array(&data) == 0)
		return (1);
	return (0);
}



//init data struct
void init_data_struct (t_general *data)
{
	data->dead_flag = 0;
	// philos = NULL;
	// data->first_philo = philos;// Es un puntero al puntero que señala la primera posicion de la lista de filosofos
	data->first_philo = NULL;
	if (pthread_mutex_init(&program->write_lock, NULL)!= 0)
		return (0);
	if (pthread_mutex_init(&program->dead_lock, NULL)!= 0)
		return (0);
	if (pthread_mutex_init(&program->eat_lock, NULL)!= 0)
		return (0);
}
//cada fiosofo tiene un tenedor, y tendra que coger el suyo y el del siguiente. por lo tanto tengo que inicializar mi tenedor y cuando este 