/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:57:14 by eescalei          #+#    #+#             */
/*   Updated: 2024/06/19 23:28:13 by eescalei         ###   ########.fr       */
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
 # include <sys/time.h>

typedef pthread_mutex_t t_mtx;
// typedef struct s_table t_table;


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

typedef enum e_status
{
	EATING,
	THINKING,
	SLEEPING,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
	DIED
}	t_philo_status;

typedef enum e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time_code;

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
	t_fork 		*first_fork;		/* first element of forks array */
	t_fork 		*second_fork;	/* last element of forks array */
	pthread_t 	thread_id;
	t_table		*table;
}		t_philo;

typedef struct s_table
{
	long int	philo_nbr;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	nbr_limit_meals;
	long int	start_simulation;
	bool		end_simulation;
	bool		all_thread_ready;
	t_mtx 		table_mtx;
	t_mtx		print_mtx;
	t_fork		*forks;
	t_philo		*philo;
}	t_table;

/* input parsing */
int	valid_input(const char *str);
int parsing_input(t_table *table, char **av);

/* struct init */
void innit_struct(t_table *table);

/* meal simulation */
void	meal_start(t_table *table);

/* setters & geteers */
void set_bool(t_mtx *mutex, bool *dest, bool value);
bool get_bool(t_mtx *mutex, bool *src);
long get_long(t_mtx *mutex, long int *src);
void set_long(t_mtx *mutex, long int *dest, long int value);
bool simulation_finished(t_table *table);

/* sync utils */
void	wait_all_thread_ready(t_table *table);
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_table *table);

/* suport_funcs */
void	*safe_malloc(size_t size);
void safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void safe_thread_handle(pthread_t *thread, void *(start_routine)(void *), void *arg, t_opcode opcode);

/* exit */
void	exit_error(char *str);

#endif