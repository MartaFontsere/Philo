/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:07:55 by mfontser          #+#    #+#             */
/*   Updated: 2024/12/03 00:04:36 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Vamos ha hacer la rutina para los philosofos
void *philo_routine(void *the_philo)
{
	t_philo *philo;
	philo = the_philo;
	pthread_mutex_lock(&philo->data->start_lock);//cuando se desbloquea el mutex, todos los filosofos querrian empezar a la vez, asi que ponemos un candado y lo bloqueamos y desbloqueamos para que empiecen uno detras de otro. Pero entonces puede que pasen primero 3 filos pares seguidos, no los tienes ordenados para optimizar que los primeros que entren sean los primeros que comen y asi no perder tiempo, no? Para que sirve realmente, no pueden empezar todos a la vez sin ese doble candado?? No, porque es la unica manera de hacer que se esperen a que todos esten creados
	pthread_mutex_unlock(&philo->data->start_lock);
	if (philo->id % 2 == 0)
		usleep (philo->data->time_to_eat / 2 * 1000); // suspende el tiempo en microsegundos, necesito reconvertir el tiempo de comer a microsegundos para que pare el tiempo suficiente. Lo paro un poco, antes que los primeros acaben de comer para que cuando aacben puedan entrar directos sin perder nada de tiempo. Les hago esperar para evitar el dead lock (que todos entren a la vez, cojan su propio tenedor y se quede la simulacion parada sin poder avanzar) 
	while (check_simulation_state (philo) == RUNNING)
	{
		if (eat (philo) == 0) 
			break;
		if (sleep_nap (philo) == 0) 
			break;
		if (think (philo) == 0) 
			break;	 
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
			data->stop_simulation = 1;
			return (0);
		}
		data->num_threads ++;
		i++;
	}
	data->t_start = get_current_time();
	pthread_mutex_unlock(&data->start_lock); //una vez creados todos los filosofos, iniciamos el contador de la simulacion y desbloqueamos el candado para que los filosofos puedan empezar.
    return (1);
}

void run_simulation (t_general *data)
{
	create_philos_threads(data);
	supervise_simulation(data);
}
