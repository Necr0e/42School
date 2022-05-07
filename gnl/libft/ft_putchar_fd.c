/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:22:18 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/09 13:57:35 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function prints a character to the file descriptor.	*/
/*	file descriptors: 0, input, 1, output, 2 error.				*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
