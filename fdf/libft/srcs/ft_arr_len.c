/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:14:46 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/13 15:15:56 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

int	ft_arr_rows(char **arr)
{
	int	i;
	int	j;

	if (!arr)
		return (-1);
	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int) ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]);
		i++;
	}
	return (j);
}

int	ft_arr_cols(char **arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
