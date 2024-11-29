/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:41:57 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 23:08:48 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

is_alive (t_philo *philo)
{
	if (!philo)
		return (0);
	pthread_mutex_lock (&philo->d_status);
	if (!philo->life_status)
	{
		pthread_mutex_unlock (&philo->d_status); // Es mas optimo asi que crear una variable, igualarla a 1 o 0, y hacer el unlock al final y retornar esa variable. Asi no espera hasta el final para mandar la info (no tarda tanto), no usas una variable que no necesitas (no ocupas memoria, el ordenador gasta tiempo en declarar y asignarle valor). Y es mas rapido si hay un solo if, no tiene que meterse en el if else a comprobar. Igual son nanosegundos que tarda, pero es mas optimo si la tengo que llamar muchas veces, como es el caso.
		return (1);
	}
	pthread_mutex_unlock (&philo->d_status);
	return (0);
}


