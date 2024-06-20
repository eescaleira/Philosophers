/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:09:30 by eescalei          #+#    #+#             */
/*   Updated: 2024/06/20 02:19:40 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/* 1 mili = 1000 micro */

int main(int ac, char **av)
{
	t_table table;
	if( 5 == ac || 6 == ac)
	{
		parsing_input(&table, av);
		innit_struct(&table);
		meal_start(&table);		
		//clean
	}
	else
		exit_error(NULL);//error exit "wrong input"
	// printf("philo_nbr: %li\n", table.philo_nbr);
	// printf("time_to_die: %li\n", table.time_to_die);
	// printf("time_to_eat: %li\n", table.time_to_eat);
	// printf("time_to_sleep: %li\n", table.time_to_sleep);
	// printf("nbr_limit_meals: %li\n", table.nbr_limit_meals);

}