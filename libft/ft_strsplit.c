/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:42 by oseitama          #+#    #+#             */
/*   Updated: 2022/01/11 16:01:22 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The main function. Allocates memory to a fresh string, splits string	*/
/*	into a table with c being the seperating character.  Iterates through 	*/
/*	string copying substrings of each word into the new fresh table.		*/
/*	uses the three helper functions above. returns a table of words.		*/

/*	This function iterates through the pointer and frees the memory 		*/
/*	in the table in case of errors.											*/

static char	**ft_freetable(char **str, char len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_strsplit(const char *src, char c)
{
	char	**str;
	int		words;
	int		i;
	int		j;

	if (!src || !c)
		return (NULL);
	words = ft_wordcount(src, c);
	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	while (i < words)
	{
		while (src[j] == c)
			j++;
		str[i] = ft_strsub(&src[j], 0, ft_wordlen(&src[j], c));
		if (str[i] == NULL)
			return (ft_freetable(str, i));
		j = j + ft_wordlen(&src[j], c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
