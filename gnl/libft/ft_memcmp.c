/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:28:40 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:29:59 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function compares two memory areas up to n bytes.		*/
/* returns either a positive, negative or 0. depending on 		*/
/* if the n bytes in s1 is less than, equal or greater than s2.	*/

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1 == str2 || len == 0)
		return (0);
	while (len--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (len)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
