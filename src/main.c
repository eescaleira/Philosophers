/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:09:30 by eescalei          #+#    #+#             */
/*   Updated: 2024/04/16 17:05:43 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/* 1 mili = 1000 micro */

int main(int ac, char **av)
{
	t_table table;
	if( 5 == ac|| 6 == ac)
	{
		//parse
		parsing_input(&table, av);
		//innit all structs
		//dinner
		//clean
	}
	else
		exit_error(NULL);//error exit "wrong input"
}