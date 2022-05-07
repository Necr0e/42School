/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:56:48 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:28:53 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function copies up to n bytes of src to dest stopping at c.		*/
/* returns first character after c is found or null if c is not found.	*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dst;

	i = 0;
	source = (unsigned char *)src;
	dst = (unsigned char *)dest;
	while (i < len)
	{
		dst[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
