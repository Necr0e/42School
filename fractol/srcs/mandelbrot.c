/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:34:32 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/15 02:48:23 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

int	mandelbrot_iteration(t_complex z, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	c;

	mlx->iter = 0;
	c.real = ((x * mlx->xscale) - mlx->zoom_x);
	c.img = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.img * z.img) < 4) && mlx->iter < mlx->max_iter)
	{
		result.real = ((z.real * z.real) - (z.img * z.img)) + c.real;
		result.img = (2 * z.img * z.real) + c.img;
		z = result;
		mlx->iter++;
	}
	return (mlx->iter);
}

void	light_mandelbrot(t_display *mlx)
{
	int			x;
	int			y;
	t_complex	z;

	z.real = 0.0;
	z.img = 0.0;
	y = 0;
	while (y < SIDE)
	{
		x = 0;
		while (x < SIDE)
		{
			mlx->iter = mandelbrot_iteration(z, x, y, mlx);
			//pixels_image
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 5, 0, 0xffffff, "Press space for help.");
	mlx_string_put(mlx->init, mlx->win, 700, 770, 0xffffff, "By OSeitama");
	if (mlx->help_m == -1)
		help_menu(mlx);
}
