/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:45:05 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 16:04:39 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_menu(t_display *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_string_put(mlx->init, mlx->win, 220, 200, 0xFFFF00, "---------- HELP MENU---------");
	mlx_string_put(mlx->init, mlx->win, 200, 250, 0xffffff, "use the mouse wheel to zoom in & out");
	mlx_string_put(mlx->init, mlx->win, 200, 300, 0xffffff, "hey you can change the color");
	mlx_string_put(mlx->init, mlx->win, 200, 350, 0xffffff, "to change the value of Red use r/t");
	mlx_string_put(mlx->init, mlx->win, 200, 400, 0xffffff, "to change the value of Green use g/h");
	mlx_string_put(mlx->init, mlx->win, 200, 450, 0xffffff, "to change the value of Blue use b/n");
	mlx_string_put(mlx->init, mlx->win, 200, 500, 0xffffff, "use the arrows to move the image ");
	mlx_string_put(mlx->init, mlx->win, 200, 550, 0xffffff, "close help by pressing the space bar");
	mlx_string_put(mlx->init, mlx->win, 220, 600, 0xFFFF00, "----------- SEE YOU!!---------");
}

void	draw_pixel(t_display *mlx, int x, int y, int color)
{
	char	*add;

	add = mlx->img->addr + ((y * mlx->img->line_len) + x * (mlx->img->bpp / 8));
	*(unsigned int *)add = color;
}

t_display	*mlx_initialization(void)
{
	t_display	*mlx;

	mlx = (t_display *)malloc(sizeof(t_display));
	if (!mlx)
		return (NULL);
	mlx->img = (t_img *)malloc(sizeof(t_img));
	if (!mlx->img)
	{
		free(mlx);
		return (NULL);
	}
	mlx->color = (t_color *)malloc(sizeof(t_color));
	if (!mlx->color)
	{
		free(mlx->img);
		free(mlx);
		return (NULL);
	}
	set_values(mlx);
	return (mlx);
}

void	set_values(t_display *mlx)
{
	mlx->xscale = 4.0 / SIDE;
	mlx->yscale = 4.0 / SIDE;
	mlx->move_x = 0.0;
	mlx->move_y = 0.0;
	mlx->zoom_x = 2.0;
	mlx->zoom_y = 2.0;
	mlx->xcoord = 0.0;
	mlx->ycoord = 0.0;
	mlx->max_iter = 60;
	mlx->position = 1;
	mlx->help_m = 1;
	mlx->color->startr = 0;
	mlx->color->endr = 255;
	mlx->color->startg = 0;
	mlx->color->endg = 255;
	mlx->color->startb = 0;
	mlx->color->endb = 255;
}

int	handle_lighting_events(t_display *mlx)
{
	if (mlx->fractal == 1)
		light_mandelbrot(mlx);
	else if (mlx->fractal == 2)
		light_julia(mlx);
	else if (mlx->fractal == 3)
		light_burning_ship(mlx);
	return (1);
}
