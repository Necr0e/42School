/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:34:34 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:32:23 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
