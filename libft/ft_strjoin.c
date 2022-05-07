/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:58:52 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/09 14:54:38 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function takes two strings in parameters s1 and s2 and  		*/
/*	allocates memory in a new string for their combined length.			*/
/*	It then combines the two strings into the new string.				*/
/*	Returns the new string otherwise NULL.								*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		length;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		length = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (!str)
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
