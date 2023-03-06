/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:22:18 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:27:24 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	This function prints a character to the file descriptor.	*/
/*	file descriptors: 0, input, 1, output, 2 error.				*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
