/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:12 by eescalei          #+#    #+#             */
/*   Updated: 2024/06/19 23:32:14 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void 	write_status(t_philo *philo, t_philo_status status)
{
	long elapsed;
	
	elapsed = gettime(MILLISECONDS) - philo->table->start_simulation;
	safe_mutex_handle(&philo->table->print_mtx, LOCK);
	if(THINKING == status)
		printf("%ld %d is thinking\n", elapsed, philo->philo_id);
	else if(EATING == status)
		printf("%ld %d is eating\n", elapsed, philo->philo_id);
	else if(SLEEPING == status)
		printf("%ld %d is sleeping\n", elapsed, philo->philo_id);
	else if(DIED == status)
		printf("%ld %d died\n", elapsed, philo->philo_id);
	else if(TAKING_FIRST_FORK == status || TAKING_SECOND_FORK == status)
		printf("%ld %d has taken a fork\n", elapsed, philo->philo_id);
	else
		printf("invalid status code\n");
}

void	exit_error(char *str)
{
	
	exit(1);
}