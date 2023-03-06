/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:02:19 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 16:11:17 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	error_event(t_display *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	free(mlx->color);
	free(mlx->img);
	free(mlx);
	exit (0);
}

void	mandelbrot(t_display *mlx)
{
	mlx = initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol by Oseitama");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
				&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fractal = 1;
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win, 17, 0, &error_event, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_loop_hook(mlx->init, &handle_lighting_events, mlx);
	mlx_loop(mlx->init);
}

void	julia(t_display *mlx)
{
	mlx = initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol by Oseitama");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
				&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fractal = 2;
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win, 17, 0, &error_event, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_hook(mlx->win, 6, 1L << 0, &mouse_coord, mlx);
	mlx_loop_hook(mlx->init, &handle_lighting_events, mlx);
	mlx_loop(mlx->init);
}

void	burningship(t_display *mlx)
{
	mlx = initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol by Oseitama");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
				&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fractal = 3;
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win, 17, 0, &error_event, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_loop_hook(mlx->init, &handle_lighting_events, mlx);
	mlx_loop(mlx->init);
}
