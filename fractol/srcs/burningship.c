/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:43:00 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 15:50:42 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burningship_iteration(t_complex c, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	z;

	mlx->iter = 0;
	z.real = ((x * mlx->xscale) - mlx->zoom_x);
	z.img = ((y * mlx->yscale) - mlx->zoom_y);
	while (((c.real * c.real) + (c.img * c.img) < 4) && mlx->iter < mlx->max_iter)
	{
		result.real = (ft_abs(c.real) * ft_abs(c.real) - \
						(ft_abs(c.img) * ft_abs(c.img)));
		result.real += z.real;
		result.img = (2 * ft_abs(c.img) * ft_abs(c.img)) + z.img;
		c = result;
		mlx->iter++;
	}
	return (mlx->iter);
}

void	light_burningship(t_display *mlx)
{
	int			start_x;
	int			start_y;
	t_complex	c;

	c.real = 0.0;
	c.img = 0.0;
	start_y - 0;
	while (start_y < SIDE)
	{
		start_x = 0;
		while (start_x < SIDE)
		{
			mlx->iter = burningship_iteration(c, start_x, start_y, mlx);
			if (mlx->iter == mlx->max_iter)
				draw_pixel(mlx, start_x, start_y, 0x000000);
			else
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
