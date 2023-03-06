/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:47:59 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:35:33 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	This function finds the first occurance of start until len and saves it	*/
/*	in a fresh string allocating memory for it in the process.				*/
/*	returns the new string. if start or len aren't valid, 					*/
/*	behavior is undefined.													*/

char	*ft_strsub(char const *src, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	if (start > ft_strlen(src))
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len && src[start] != '\0')
	{
		str[i] = src[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
