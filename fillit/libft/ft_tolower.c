/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:56:03 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/02 10:40:38 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function converts uppercase characters to lowercase.	*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = (c - 'A' + 'a');
	}
	return (c);
}
