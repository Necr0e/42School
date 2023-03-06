/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:41:07 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:27:21 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	Gets the power of a number.
*/

long long	ft_pow(long long nbr, int p)
{
	int		out;

	out = 1;
	if (p == 0)
		return (1);
	while (p-- > 0)
		out *= nbr;
	return (out);
}
