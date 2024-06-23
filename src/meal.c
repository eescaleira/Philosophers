/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:55:09 by eescalei          #+#    #+#             */
/*   Updated: 2024/06/22 15:02:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void *meal_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	printf("philo %d is thinking\n", philo->philo_id);
	wait_all_thread_ready(philo->table);
	while(!simulation_finished(philo->table))
	{
		if(philo->full)
			break ;
		eat(philo);
		sleep_philo(philo);
		think(philo);	
	}
	return (NULL);
}

void	meal_start(t_table *table)
{
	int i;

	i = 0;
	if(0 == table->philo_nbr)
		return ;
	else if(1 == table->philo_nbr)
		;//To Do
	else
		while(i < table->philo_nbr)
		{
			safe_thread_handle(&table->philo[i].thread_id, meal_simulation, &table->philo[i], CREATE);
			i++;
		}
	safe_thread_handle(&table->monitoring_thread, monitoring, table, CREATE);
	table->start_simulation = gettime(MILLISECONDS);
	set_bool(&table->table_mtx, &table->all_thread_ready, true);
	i = 0;
	while(i < table->philo_nbr)
	{
		safe_thread_handle(&table->philo[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_bool(&table->table_mtx, &table->end_simulation, true);
	
}
