/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:18:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:23:09 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* This function adds a new element to to the list.		*/
/* if the list doesn't exist, it creates a new list.	*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
