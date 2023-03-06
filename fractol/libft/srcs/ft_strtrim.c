/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:24:09 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/28 00:35:36 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*	This function takes a string and trims out the whitespaces			*/
/*	at the start and end of the string.  Returns a copy of s if 		*/
/*	no whitespaces were found or NULL if memory allocation failed.		*/
/*	If successful returns a substring of string s without whitespaces.	*/

char	*ft_strtrim(char const *src)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	if (!src)
		return (NULL);
	while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n')
		start++;
	if (src[start] == '\0')
		return (ft_strnew(1));
	end = start;
	while (src[end] != '\0')
		end++;
	end--;
	while (src[end] == ' ' || src[end] == '\t' || src[end] == '\n')
		end--;
	return (ft_strsub(src, start, end - start + 1));
}
