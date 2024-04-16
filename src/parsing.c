/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:02:01 by eescalei          #+#    #+#             */
/*   Updated: 2024/04/16 18:05:03 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int check_positive_number(int n)
{
	if(n <= 0)
		//error exit "invalide input"
	return (n);
}

void innit_table_values(t_table *table, char **av)
{
	table->philo_nbr = check_positive_number(ft_atoi(av[1]));
	table->time_to_die = check_positive_number(ft_atoi(av[2]));
	table->time_to_eat = check_positive_number(ft_atoi(av[3]));
	table->time_to_sleep = check_positive_number(ft_atoi(av[4]));
	table->nbr_limit_meals = -1;
	if(NULL != av[5])
		table->nbr_limit_meals = check_positive_number(ft_atoi(av[5]));
}

int parsing_input(t_table *table, char **av)
{
	// check if number
	
	// check limits ints
	
	// innit values table
	innit_table_values(table, av);
}