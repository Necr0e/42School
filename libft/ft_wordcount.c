/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:24:41 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/20 15:27:36 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The wordcount function gets the number of words in our string to split.	*/
/*	This is done by increasing word count when the index is not equals c.	*/
/*	returns the number of words.                                            */

int	ft_wordcount(char const *src, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (src[i])
	{
		while ((src[i] == c) && (src[i]))
			i++;
		if ((src[i] != c) && src[i])
		{
			i++;
			words++;
			while ((src[i] != c) && (src[i]))
				i++;
		}
	}
	return (words);
}
