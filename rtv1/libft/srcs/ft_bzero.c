/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:26:24 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:18:15 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	This function takes a pointer and the amount of bytes to erase.	 */
/*	Erases n bytes at pointer s by setting the value to 0.			 */

void	ft_bzero(void *src, size_t len)
{
	ft_memset(src, 0, len);
}
