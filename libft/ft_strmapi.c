/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:21:48 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/19 23:37:49 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function makes sure the parameters exist and then,			*/
/*	allocates memory to a fresh string.	It then iterated through	*/
/*	the string running function f at each index after the given		*/
/*	starting idex value.  Returns the fresh index.					*/

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!src || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = f(i, src[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
