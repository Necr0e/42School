/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:43:37 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/31 16:20:42 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_free(void *freeable)
{
	if (freeable)
		free(freeable);
	freeable = NULL;
	return (NULL);
}

void	**ft_free_double_ptr(void **freeable)
{
	int		i;

	if (freeable)
	{
		i = 0;
		while (freeable[i])
		{
			free(freeable[i]);
			i++;
		}
		free(freeable);
	}
	freeable = NULL;
	return (NULL);
}
