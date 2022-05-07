/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:37:23 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:34:14 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function searches string s for the first occurance of character c.	*/

char	*ft_strchr(const char *src, int c)
{
	char	*str;

	str = (char *)src;
	while ((*str != '\0') && (*str != c))
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}
