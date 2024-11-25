/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:40:28 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/25 03:38:29 by mfontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

/*COLORS*/
# define END "\x1b[0m"
# define RED "\e[1;91m"
# define YELLOW "\e[1;93m"
# define BLUE "\e[1;94m"
# define GREEN "\e[1;92m"
# define CYAN "\e[1;96m"
# define PURPLE "\e[1;95m"
# define ORANGE "\e[1;38;2;255;128;0m"

# define MAX_INT "2147483647"

// # define PHILO_MAX 201

typedef struct s_philo // estructura philos, con la info de cada uno de ellos
{
	int 				id;
	pthread_mutex_t		tenedor_propio; // no es puntero porque lo inicializa cada uno //no tengo tenedores en si, es el propio semaforo para decir si puedo hacer una accion o no. Tengo un semaforo por filo, y para hacer la accion necesito que los dos semaforos contiguos esten libres
	pthread_mutex_t		*tenedor_externo; // es puntero porque toma la direccion de memoria del tenedor del filo anterior.
	struct s_general	*data;
}					t_philo;


typedef struct s_general
{
	int 				philo_num;
	t_philo 			*first_philo; //puntero a una estructura de tipo t_philo 
	//SI LO HAGO DOBLE PUNTERO COMO GESTIONAR LA CREACION DE LA ESTRUCTURA, YA TENGO LOS DOS PUNTEROS AQUI.
	//OSEA CUANDO DIGO QUE T_PHILO ES UN PUNTERO, ESO LO ESTOY DICIENDO YO, NO? PODRIA DECIR PERFECTAMENTE QUE ES SIMPLE, SIN PUNTERO Y NO CAMBIARIA NADA EN LA ESTRUCTURA, ESO LO DEFINO YO A PRINCIPIO EN BASE A LO QUE QUIERO.
	int					dead_flag;
	pthread_mutex_t 	dead_lock; 
	pthread_mutex_t 	eat_lock; 
	pthread_mutex_t 	write_lock; 

	int 				time_to_die;
	int 				time_to_eat;
	int 				time_to_sleep;
	int 				num_eats_each_philo;

}						t_general;



//MAIN


//PARSING
int	params_are_valids(char **argv);
int	prepare_params(t_general *data, char **argv);


//BUILD PHILOS
int build_philos_list (t_general *data);
t_philo create_philos (void);
void	put_new_list_philo_node(t_general *data, t_philo *new_philo);


//UTILS
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isspace(int c);
int	ft_atoi(const char *str);



// ERROR_MESSAGES
void wrong_number_of_parameters(void);
void error_empty_string();
void error_negative_sign();
void error_positive_sign();
void error_chars_found();
void error_space_after_sign();


#endif