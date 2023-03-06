/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:51:43 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:31:08 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* This function iterates through a string and applies function f to it.	*/

void	ft_striter(char *src, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	if (src && f)
	{
		while (src[i] != '\0')
		{
			f(&src[i]);
			i++;
		}
	}
}
