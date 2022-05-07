/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:39:43 by oseitama          #+#    #+#             */
/*   Updated: 2022/02/16 11:23:14 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function deletes the string as and frees the memory.	*/

void	ft_strdel(char **as)
{
	if (!as && !*as)
		ft_memdel((void **)as);
}
