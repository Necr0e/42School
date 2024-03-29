/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:12:19 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:24:11 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	Allocates memory in the amount of the size parameter to the pointer.	*/
/*	Sets initialize value to 0. If size doesn't exist returns NULL.			*/

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size)
	{
		ptr = (void *)malloc(sizeof(ptr) * (size));
		if (ptr)
		{
			ft_memset(ptr, 0, size);
			return (ptr);
		}
	}
	return (NULL);
}
