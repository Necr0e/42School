/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:46:00 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:34:40 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function iterates through a string and empties it	*/
/*	by setting every value to \0.							*/

void	ft_strclr(char *str)
{
	if (str)
	{
		while (*str)
		{
			*str = '\0';
			str++;
		}
	}
}
