/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:40:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/01/08 13:20:40 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function takes a string and converts it to it's integer value.		*/
/*	Returns integer value of inputted string. Checks for whitespaces with	*/
/*	ft_isspace function.													*/

int	ft_atoi(const char *ptr)
{
	unsigned int	i;
	long			sign;
	long			res;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_isspace(ptr[i]))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = res * 10 + ptr[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}
