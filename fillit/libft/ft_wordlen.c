/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:25:26 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/20 15:36:37 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The wordlen function counts the length of each word by 					*/
/*	iterating through the string.  When the string's index is not c			*/
/*	Returns the index.														*/

int	ft_wordlen(char const *src, char c)
{
	int	i;

	i = 0;
	while ((src[i] != c) && (src[i]))
		i++;
	return (i);
}
