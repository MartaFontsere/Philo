/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:07:55 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/30 00:07:46 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Mejor manera para empezar, hacer un archivo de prueba en el que creo threads, veo que hacen y luego crear mutex y ver como interactuan. Asi aprendes la mecanica de los nuevos conceptos




int main (int argc, char **argv)
{
	t_general		data;
	int i;

	if (argc > 6 || argc < 5)
	{
		wrong_number_of_parameters();
		return (1);
	}
	
	//parsing
	if (params_are_valids(&data, argv) == 0)
		return (1);
	//inits
	if (init_data_struct(&data) == 0)
		return (1);
	if (build_philos_and_forks(&data) == 0)
		return (1);
	if (init_philos_struct(&data) == 0)
		return (1);
	//simulacion
	if (run_simulation(&data) == 0)
		return (1);
	

	
	 //ELIMINAR CADA UNO DE LOS HILOS CON UN JOIN
	i = 0;
	while (i < data.philo_num)
	{
		pthread_join(data.philos[i].thread_id, NULL);
		i++;
	}
//FALTA LIMPIAR MALLOCS
	//deberia cerrar bien los threats los mutex los leaks i salir limpio
	return (0);
}
