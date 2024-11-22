/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:40:28 by mfontser          #+#    #+#             */
/*   Updated: 2024/11/21 02:00:14 by mfontser         ###   ########.fr       */
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


typedef struct s_philo
{
	int 		id;
	int 		to_die;
	int 		to_eat;
	int 		to_sleep;
	int 		num_eats_each_philo;

}				t_philo;


typedef struct s_general
{
	int 		philo_num;
	t_philo 	*philos; // estructura philos, con la info de cada uno de ellos
	int			dead_flag;
	pthread_mutex_t 	bloqueo_muerto; 
	pthread_mutex_t 	bloqueo_comida; 
	pthread_mutex_t 	bloqueo_escritura; 

}				t_general;



//MAIN
int	init_data_values(t_general *data, char **argv);

//PARSING
int	params_are_valids(char **argv);


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