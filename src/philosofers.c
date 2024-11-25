/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:07:55 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 22:15:22 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Mejor manera para empezar, hacer un archivo de prueba en el que creo threads, veo que hacen y luego crear mutex y ver como interactuan. Asi aprendes la mecanica de los nuevos conceptos


//Vamos ha hacer la rutina para los philosofos
void *philoso_routine(void *the_philo)
{
	t_philo *philo;
	philo = the_philo;
	while(!philo->data->dead_flag) // entro en la funcion con cada filosofo, y para ver si tengo que parar chequeo la flag. Para eso, desde cada filosofo voy a chequearla, porque todos los punteros data de cada filosofo apuntan al mismo sitio. Lo estoy chequeando desde distintos filosofos pero todo el rato miro la misma info.
	{
		//hola soy el philosfo numero
		printf("Soy el philo numero %d\n", philo->id);
		usleep(1000);
	}
	return (NULL);
}


int create_philo_threads(t_general *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_create(&(data->philos[i].thread_id), NULL, &philoso_routine, &data->philos[i]); //esta creando un threat
		//si el threat ha fallado hago algo
		i++;
	}
    return (1);
}

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
	//creo los threats
	create_philo_threads(&data);
	while(1)
	{
		usleep(10000);
		//data->dead_flag = 1;
		break;
	}
	//deberia cerrar bien los threats los mutexz los leaks i salir limpio
	return (0);
}
