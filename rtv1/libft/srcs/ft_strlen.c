/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:57:34 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:34:47 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* This function gets the length of a string.	*/

size_t	ft_strlen(const char *src)
{
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}
