/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:12:39 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/29 17:46:37 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function first checks if the inputted list exists.			*/
/*	It then creates a fresh list with the content of lst and		*/
/*	runs the function f in each node. Returns the fresh list.		*/

/*	Frees the memory contained in the link's content as well as 	*/
/*	the link itself.  Sets link to NULL.							*/

static void	ft_free_link(t_list **link)
{
	free((*link)->content);
	free(*link);
	*link = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	if (!newlist)
		return (NULL);
	if (lst->next)
	{
		newlist->next = ft_lstmap(lst->next, f);
		if (!newlist->next)
			ft_free_link(&newlist);
	}
	return (newlist);
}
