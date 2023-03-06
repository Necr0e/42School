/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:04:44 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:34:40 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	This function iterates through a string applying function f to a given	*/
/*	index in the string. 													*/

void	ft_striteri(char *src, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!src || !f)
		return ;
	while (src[i] != '\0')
	{
		f(i, src + i);
		i++;
	}
}
