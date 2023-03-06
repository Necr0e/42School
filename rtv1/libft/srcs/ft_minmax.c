/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:09:01 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:27:17 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	Returns either the minimum or maximum value
**	Depending on the function used.
*/
int ft_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int ft_min(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}
