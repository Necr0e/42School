/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:18:29 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:28:41 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* This function prints a string and ends the line with a newline.	*/

void	ft_putendl(const char *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	ft_putchar('\n');
}
