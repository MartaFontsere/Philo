/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:40:28 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/29 22:01:11 by mfontser         ###   ########.fr       */
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

//# define PHILO_MAX 201

typedef struct s_philo // estructura philos, con la info de cada uno de ellos
{
	int 				id;
	pthread_t 			thread_id;
	pthread_mutex_t		*right_fork; // es puntero porque se supone que todos los tenedores estan en la mesa y yo tengo una lista de tenedores y al primero le asigno el primer tenedor y el del filo anterior. Todo son punteros. no era puntero porque lo inicializa cada uno //no tengo tenedores en si, es el propio semaforo para decir si puedo hacer una accion o no. Tengo un semaforo por filo, y para hacer la accion necesito que los dos semaforos contiguos esten libres
	pthread_mutex_t		*left_fork; // es puntero porque toma la direccion de memoria del tenedor del filo anterior.
	pthread_mutex_t		*d_status;
	int  				dead_status;
	pthread_mutex_t		*n_meals;
	int  				num_meals;
	pthread_mutex_t		*l_meal;
	unsigned int		last_meal;
	struct s_general	*data;
}						t_philo;


typedef struct s_general
{
	int 				philo_num;
	t_philo 			*philos; //puntero a una estructura de tipo t_philo. podria hacerlo doble puntero, pero eso requeriria hacer malloc de cada una de las posiciones que ocupen los filos. Asi solo hago uno de tamano tphilo para cada philo y ya.  

	// T_PHILO ES UNA ESTRUCTURA QUE TIENE UN TAMANO SEGUN LA INFO UE ALMACENA. DESPUES LA VARIABLE QUE HAGA DE ESE TIPO PODRA SER PUNTERO O DOBLE PUNTERO, ESO LO ESTOY DICIENDO YO. PODRIA DECIR PERFECTAMENTE QUE ES SIMPLE, SIN PUNTERO Y NO CAMBIARIA NADA EN LA ESTRUCTURA, ESO LO DEFINO YO A PRINCIPIO EN BASE A LO QUE QUIERO.
	int					stop_simulation;
	pthread_mutex_t		*forks_array;
	pthread_mutex_t		*dead_status_array;
	pthread_mutex_t		*num_meals_array;
	pthread_mutex_t		*last_meal_array;
	pthread_mutex_t 	start_lock; 
	pthread_mutex_t 	write_lock; 
	pthread_mutex_t 	dead_lock; 
	unsigned int		t_start;
	int 				time_to_die;
	int 				time_to_eat;
	int 				time_to_sleep;
	int 				num_eats_each_philo;

}						t_general;



//MAIN


//PARSING
int	params_are_valids(t_general *data, char **argv);
int	check_valid_format(char **argv);
int	check_size_int(char **argv);
int	params_conversion_to_int(t_general *data, char **argv);
int check_extreme_cases (t_general *data);

//INITIALITATIONS
int init_data_struct (t_general *data);
int init_philos_struct(t_general *data);


//BUILD PHILOS AND FORKS
int build_philos_and_forks(t_general *data);
int build_philos_array (t_general *data);
int build_forks_array(t_general *data);

//TIME
unsigned int	get_current_time(void);

//UTILS
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isspace(int c);
int	ft_atoi(const char *str);


//FREE
void free_all_info(t_general *data);
void free_arrays(t_general *data);
void free_data_mutex (t_general *data);


// ERROR_MESSAGES
void wrong_number_of_parameters(void);
void error_empty_string();
void error_negative_sign();
void error_positive_sign();
void error_chars_found();
void error_space_after_sign();


#endif