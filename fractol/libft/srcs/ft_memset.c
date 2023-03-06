/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:34:34 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:25:28 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* This function sets first n bytes of memory in s with c.		*/

void	*ft_memset(void *ptr, int c, size_t len)
{
	while (len > 0)
	{
		((unsigned char *)ptr)[len - 1] = c;
		len--;
	}
	return (ptr);
}
