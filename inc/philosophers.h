/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:57:14 by eescalei          #+#    #+#             */
/*   Updated: 2024/05/16 18:17:23 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
 #define PHILOSOPHERS_H
 
 # include <unistd.h>
 # include <stddef.h>
 # include <stdlib.h>
 # include <errno.h>
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

typedef pthread_mutex_t t_mtx;
typedef struct s_table t_table;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef struct
{
	int 			fork_id;
	t_mtx			fork;
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
int	valid_input(const char *str);
int parsing_input(t_table *table, char **av);

/* suport_funcs */
void	*safe_malloc(size_t size);

/* exit */
void	exit_error(char *str);

#endif