/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:27:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/04/16 18:09:33 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_atoi(const char *str)
{
	int	res;
	int i;

	res = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 0;
		res = (str[i] - '0') + (res * 10);
		i++;
		if(i <= 10)
			// exit "value to big"
	}
	return (res);
}

