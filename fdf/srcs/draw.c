/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/16 15:32:22 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Draw map using bresenham line formula
*/
void	draw_map(t_img *img, t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	while (y + 1 <= draw->height)
	{
		x = 0;
		while (x + 1 <= draw->width)
		{
			if (x + 1 < draw->width && y + 1 < draw->height)
			{
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			}
			if (x + 1 == draw->width && y + 1 < draw->height)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			if (y + 1 == draw->height && x + 1 < draw->width)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
			x++;
		}
		y++;
	}
}

/*
**	Draw menu text
*/
void	put_menu_txt(t_fdf *mlx)
{
	int		nb_rows;
	int		gap;
	int		i;
	char	**str;

	str = ft_strsplit(MENU_TXT, '\n');
	nb_rows = ft_arr_rows(str);
	gap = MENU_HEIGHT / nb_rows;
	i = 0;
	while (i < nb_rows && str[i])
	{
		mlx_string_put(mlx->mlx, mlx->win, MENU_X0 + MARGIN / 2, \
			MENU_Y0 + MARGIN / 2 + i * gap, MENU_COLOR, str[i]);
		i++;
	}
	free_split(str);
}

int	color_fade(t_map a, t_map z, t_map i)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	prog;

	prog = (ft_abs(i.pix_x - a.pix_x) + ft_abs(i.pix_y - a.pix_y)) * \
	100 / (ft_abs(z.pix_x - a.pix_x) + ft_abs(z.pix_y - a.pix_y));
	t = ((get_t(z.color) - get_t(a.color)) * prog / 100) + get_t(a.color);
	r = ((get_r(z.color) - get_r(a.color)) * prog / 100) + get_r(a.color);
	g = ((get_g(z.color) - get_g(a.color)) * prog / 100) + get_g(a.color);
	b = ((get_b(z.color) - get_b(a.color)) * prog / 100) + get_b(a.color);
	return (create_trgb(t, r, g, b));
}

int	get_opposite_color(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(t, r, g, b));
}
