/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:00:35 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/29 03:03:14 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_ptr;
	size_t	total_size;

	total_size = count * size;
	heap_ptr = malloc(total_size);
	if (heap_ptr == NULL)
		return (NULL);
	ft_bzero(heap_ptr, total_size);
	return (heap_ptr);
}
