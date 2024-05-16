/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:09:30 by eescalei          #+#    #+#             */
/*   Updated: 2024/05/16 14:28:36 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/* 1 mili = 1000 micro */

int main(int ac, char **av)
{
	t_table table;
	if( 5 == ac || 6 == ac)
	{
		//parse
		parsing_input(&table, av);
		//innit
		// innit_structs(&table);
		//dinner
		//clean
	}
	else
		exit_error(NULL);//error exit "wrong input"
	printf("philo_nbr: %li\n", table.philo_nbr);
	printf("time_to_die: %li\n", table.time_to_die);
	printf("time_to_eat: %li\n", table.time_to_eat);
	printf("time_to_sleep: %li\n", table.time_to_sleep);
	printf("nbr_limit_meals: %li\n", table.nbr_limit_meals);

}