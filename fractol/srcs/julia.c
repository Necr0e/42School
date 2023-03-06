/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:35:03 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 15:42:11 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_iteration(t_complex c, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	z;

	mlx->iter = 0;
	z.real = ((x * mlx->xscale) - mlx->zoom_x);
	z.img = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.img * z.img) < 4) && mlx->iter < mlx->max_iter)
	{
		result.real = ((z.real * z.real) - (z.img * z.img)) + c.real;
		result.img = (2 * z.img * z.real) + c.img;
		z = result;
		mlx->iter++;
	}
	return (mlx->iter);
}

void	light_julia(t_display *mlx)
{
	int			start_x;
	int			start_y;
	t_complex	c;

	c.real = mlx->xcoord;
	c.img = mlx->ycoord;
	start_y - 0;
	while (start_y < SIDE)
	{
		start_x = 0;
		while (start_x < SIDE)
		{
			mlx->iter = julia_iteration(c, start_x, start_y, mlx);
			draw_pixel(mlx, start_x, start_y, color_pixels(mlx));
			start_x++;
		}
		start_y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 5, 0, 0xffffff, "Press space for help.");
	mlx_string_put(mlx->init, mlx->win, 700, 770, 0xffffff, "By OSeitama");
	if (mlx->help_m == -1)
		help_menu(mlx);
}
