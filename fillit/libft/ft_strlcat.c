/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:55:12 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/28 12:21:19 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function gets the total length of dest if src was appended to it.	*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*source;
	size_t		len_dst;
	size_t		len_src;
	size_t		res;
	size_t		i;

	source = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(source);
	res = 0;
	i = 0;
	if (size > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + size;
	while (source[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = source[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
