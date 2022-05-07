/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:08:09 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/28 12:25:22 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function finds the last occurance of character c in the string.	*/
/*	Starts loop at end in order to find the last occurance the quickest.	*/

char	*ft_strrchr(const char *src, int c)
{
	int	len;

	len = ft_strlen(src);
	while (len >= 0)
	{
		if (src[len] == c)
			return ((char *)&src[len]);
		len--;
	}
	return (NULL);
}
