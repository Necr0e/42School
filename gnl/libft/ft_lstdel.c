/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:12:03 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/09 13:49:06 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function first checks that the list and del exist.				*/
/*	It then iterates through the list deleting the content,				*/
/*	and freeing the memory. 											*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}
