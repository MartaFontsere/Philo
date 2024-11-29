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



//Vamos ha hacer la rutina para los philosofos
void *philo_routine(void *the_philo)
{
	t_philo *philo;
	philo = the_philo;
	pthread_mutex_lock(&philo->data->start_lock);//cuando se desbloquea el mutex, todos los filosofos querrian empezar a la vez, asi que ponemos un candado y lo bloqueamos y desbloqueamos para que empiecen uno detras de otro. Pero entonces puede que pasen primero 3 filos pares seguidos, no los tienes ordenados para optimizar que los primeros que entren sean los primeros que comen y asi no perder tiempo, no? Para que sirve realmente, no pueden empezar todos a la vez sin ese doble candado??
	pthread_mutex_unlock(&philo->data->start_lock);
	if (philo->id % 2 == 0)
		usleep (philo->data->time_to_eat / 2 * 1000); // suspende el tiempo en microsegundos, necesito reconvertir el tiempo de comer a microsegundos para que pare el tiempo suficiente. Lo paro un poco, antes que los primeros acaben de comer para que cuando aacben puedan entrar directos sin perder nada de tiempo. Les hago esperar para evitar el dead lock (que todos entren a la vez, cojan su propio tenedor y se quede la simulacion parada sin poder avanzar) 
	while (is_alive (philo))
	{
		take_forks(philo);

		 
	}




	return (NULL);
}


int create_philos_threads(t_general *data)
{
	int i;

	i = 0;

	pthread_mutex_lock(&data->start_lock);//bloqueo el inicio de la rutina para que todos tengan que esperarse hasta que acabe el bucle para que se desbloquee	
	while (i < data->philo_num)
	{
		if (pthread_create(&(data->philos[i].thread_id), NULL, &philo_routine, &data->philos[i]) != 0) //esta creando un threat
		{
			write(2, "ABORT: ERROR WHILE CREATING A THREAD\n", 37);
			return (0);
		}
		i++;
	}
	data->t_start = get_current_time();
	//INICIALIZAR EL TIEMPO DE LA ULTIMA COMIDA DE CADA UNO DE LOS FILOSOFOS
	pthread_mutex_unlock(&data->start_lock);		//una vez creados todos los filosofos, iniciamos el contador de la simulacion y desbloqueamos el candado para que los filosofos puedan empezar.
    //INICIAR EL SUPERVISOR
    //ELIMINAR CADA UNO DE LOS HILOS CON UN JOIN

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
	if (params_are_valids(&data, argv) == 0)
		return (1);
	
	//inits
	if (init_data_struct(&data) == 0)
		return (1);
	if (build_philos_and_forks(&data) == 0)
		return (1);
	if (init_philos_struct(&data) == 0)
		return (1);

	//creo los threats
	if (create_philos_threads(&data) == 0)
		return (1);

	// while(1)
	// {
	// 	usleep(5000);
	// 	data.dead_flag = 1;
	// 	break;
	// }
	//deberia cerrar bien los threats los mutex los leaks i salir limpio
	return (0);
}
