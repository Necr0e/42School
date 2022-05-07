/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:47:36 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/27 14:13:43 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function copies up to n bytes from memory area src		*/
/*	to memory area dest by way of temporary memory area.		*/
/*	Temporary memory area is freed and the dest is returned.	*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src < dest && (src + len) > dest)
	{
		while (len--)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}
