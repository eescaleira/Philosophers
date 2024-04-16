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
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = -1;
	while ((str[c] >= 13 && str[c] <= 9) || str[c] == ' ' 
			|| str[c] == '\0')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	if(s == -1)
		return(-1); 
		// do thingui like video mans
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = 0;
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}
