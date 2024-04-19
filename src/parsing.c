/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:02:01 by eescalei          #+#    #+#             */
/*   Updated: 2024/04/19 14:15:31 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

char	*valid_input(const char *str)
{
	while ((*str >= 13 && *str <= 9) || *str == ' ' 
			|| *str == '\0')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			exit_error(NULL);// change to exi`t_error("negative values not acepted")
		str++;
	}
	return ((char *)str);
}

int check_positive_output(int n)
{
	if(n <= 0)
		exit_error(NULL);//error exit "invalide input"
	return (n);
}

void innit_table_values(t_table *table, char **av)
{
	table->philo_nbr = check_positive_output(ft_atoi(av[1])) * 1e3;
	table->time_to_die = check_positive_output(ft_atoi(av[2])) * 1e3;
	table->time_to_eat = check_positive_output(ft_atoi(av[3])) * 1e3;
	table->time_to_sleep = check_positive_output(ft_atoi(av[4])) * 1e3;
	table->nbr_limit_meals = -1;
	if(NULL != av[5])
		table->nbr_limit_meals = check_positive_output(ft_atoi(av[5])) * 1e3;
}

int parsing_input(t_table *table, char **av)
{
	int i;

	i = 1;
	// check if number
	// check limits ints
	while(av[i] != NULL)
	{
		av[i] = valid_input(av[i]);
		// printf("%s\n", av[i]);
		if(NULL == av[i++])
			exit_error(NULL);//exit "invalid input"
			
	}
	// innit values table
	innit_table_values(table, av);
	return (0);
}
