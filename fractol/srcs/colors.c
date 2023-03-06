/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:57:40 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 15:31:01 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*fill_color(char *r, char *g, char *b)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	str[i++] = '0';
	str[i++] = 'x';
	ft_strlcat(str, r, 10);
	ft_strlcat(str, g, 10);
	ft_strlcat(str, b, 10);
	return (str);
}

char	*dec_to_hex(unsigned int num)
{
	char	*tmp;
	int		mod;
	int		i;

	i = 1;
	mod = 0;
	tmp = malloc(sizeof(char) * 4);
	while (num != 0)
	{
		mod = num % 16;
		if (mod < 10)
			tmp[i--] = mod + '0';
		else
			tmp[i--] = mod + '7';
		num = num / 16;
	}
	tmp[2] = '\0';
	return (tmp);
}

int	ft_convertcolor(int red, int green, int blue)
{
	char	*r;
	char	*g;
	char	*b;
	char	*color;
	int		res;

	r = dec_to_hex(red);
	g = dec_to_hex(green);
	b = dec_to_hex(blue);
	color = fill_color(r, g, b);
	free(r);
	free(g);
	free(b);
	res = ft_atoi_hex(color);
	free(color);
	return (res);
}

int	color_pixels(t_display *mlx)
{
	double	n;
	int		res;

	if (mlx->iter == mlx->max_iter && mlx->fractal != 2)
		return (0x000000);
	n = (double)mlx->iter / (double)mlx->max_iter;
	mlx->color->r = mlx->color->startr * (1 - n) + mlx->color->endr * n;
	mlx->color->g = mlx->color->startg * (1 - n) + mlx->color->endg * n;
	mlx->color->b = mlx->color->startb * (1 - n) + mlx->color->endb * n;
	res = ft_convertcolor(mlx->color->r, mlx->color->g, mlx->color->b);
	return (res);
}
