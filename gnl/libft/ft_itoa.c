/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:44:09 by oseitama          #+#    #+#             */
/*   Updated: 2021/12/28 13:05:30 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function takes an integer and converts it to a string.	*/
/*	Uses 2 additional functions intlen to calculate the length	*/
/*	of the integer value and printchar which prints the data.	*/

/*	Function intlen takes a number and calculates the length by	*/
/*	dividing the value by 10 until the value is 0 increasing	*/
/*	the counter each time.										*/

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*	Function printchar takes four values from itoa, the string,	*/
/*	the length, if it's a negative value and the number.		*/
/*	Prints the characters.										*/

static char	*ft_printchar(char *str, int len, int neg, int n)
{
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg > 0)
		str[0] = '-';
	return (str);
}

/*	Main function.  Allocates memory based on the length and 	*/
/*	prints the characters.										*/

char	*ft_itoa(int n)
{
	int		len;
	int		isneg;
	char	*str;

	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		n *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n) + isneg;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_printchar(str, len, isneg, n);
	return (str);
}
