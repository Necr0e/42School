/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:20:08 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/28 11:57:33 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  This function checks if the parameter character is a known whitespace.	*/
/*	If so, return 1, otherwise return 0.									*/
/*	known whitespaces: ' ', '\b', '\t', '\v', '\n', '\v', '\f', '\r'		*/

int	ft_isspace(char c)
{
	if ((c > 8 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}
