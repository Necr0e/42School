/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:46:01 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/27 14:35:02 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function copies up to n bytes of memory from src to dest.	*/
/* works with any type of data and is generally faster than strcpy	*/

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*source;

	source = NULL;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (!dst && !source)
		return (NULL);
	while (i < len)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
