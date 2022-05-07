/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:29:15 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/21 10:16:30 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function prints a string to the file descriptor	*/
/*	and ends the line with a newline.						*/
/*	file descriptors: 0, input, 1, output, 2 error.				*/

void	ft_putendl_fd(const char *str, int fd)
{
	if (!str)
		return ;
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
