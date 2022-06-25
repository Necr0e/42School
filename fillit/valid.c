/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:34:17 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/27 12:54:39 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Checks for invalid characters as well as wrong length of lines.		*/
/*	Also checks for incorrect number of # and missing \n.				*/
/*	Returns error code if any of these are failed.						*/

int	charcount(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (invalid_chars);
			if (s[i] == '#' && ++count > 4)
				return (invalid_count);
		}
		else if (s[i] != '\n')
			return (invalid_mapsize);
		i++;
	}
	if (s[i] != '\n')
		return (missing_endl);
	return (success);
}

/*	Checks connections.  6 or 8 are valid. others invalid.	*/

int	connectioncount(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}
