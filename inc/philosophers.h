/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:57:14 by eescalei          #+#    #+#             */
/*   Updated: 2024/04/16 17:38:30 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
 #define PHILOSOPHERS_H
 
 # include <unistd.h>
 # include <stddef.h>
 # include <stdlib.h>
 # include <pthread.h>
 # include <string.h>
 # include <limits.h>
 # include <ctype.h>
 # include <string.h>
 # include <stdbool.h>
 # include <stdio.h>
 # include <fcntl.h>
 # include <sys/types.h>
 # include <sys/wait.h>

typedef struct s_table t_table;

typedef struct
{
	int 			fork_id;
	pthread_mutex_t	fork;
}		t_fork;

typedef struct s_philo
{
	int 		philo_id;
	bool 		full;
	long int 	meals_counter;
	long int 	last_meal_time;
	t_fork 		*left_fork;		/* first element of forks array */
	t_fork 		*right_fork;	/* last element of forks array */
	pthread_t 	thread_id;
	t_table		*table;
}		t_philo;

struct s_table
{
	long int	philo_nbr;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	nbr_limit_meals;
	long int	start_simulation;
	bool		end_simulation;
	t_fork		*forks;
	t_philo		*philo;
};

/* input parsing */
int parsing_input(t_table *table, char **av);

/* suport_funcs */
int	ft_atoi(const char *str);

#endif