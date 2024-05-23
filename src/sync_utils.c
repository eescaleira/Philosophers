/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:29:23 by eescalei          #+#    #+#             */
/*   Updated: 2024/05/18 14:03:12 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long	gettime(t_time_code time_code)
{
	struct timeval	time;
	
	if(gettimeofday(&time, NULL));
		exit_error("gettimeofday error");
	if(SECONDS == time_code)
		return (time.tv_sec + (time.tv_usec / 1e6));
	else if(MILLISECONDS == time_code)
		return (time.tv_sec * 1e3 + (time.tv_usec / 1e3));
	else if(MICROSECONDS == time_code)
		return (time.tv_sec * 1e6 + time.tv_usec);
	else
		exit_error("invalid time code");
	return (0);
}

void	wait_all_thread_ready(t_table *table)
{
	while(get_bool(&table->table_mtx, &table->all_thread_ready))
		;
}
