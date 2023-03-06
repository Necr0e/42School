/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:51:23 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 15:58:17 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_event(int keycode, t_display *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		free(mlx->color);
		free(mlx->img);
		free(mlx);
		exit(0);
	}
	if (keycode == 49)
		mlx->help_m *= -1;
	handle_key_event(keycode, mlx);
	handle_lighting_events(mlx);
}

int	mouse_event(int button, int x, int y, t_display *mlx)
{
	if (button == 1)
	{
		mlx->position *= -1;
		return (0);
	}
	if (button == 5 || button == 4)
		handle_mouse_event(button, x, y, mlx);
	handle_lighting_events(mlx);
	return (0);

}

int	mouse_coord(int x, int y, t_display *mlx)
{
	if (mlx->position == 1)
	{
		if ((x <= SIDE && x >= 0) || (y <= SIDE && y >= 0))
		{
			mlx->xcoord = ((x * mlx->xscale) - mlx->zoom_x);
			mlx->ycoord = ((y * mlx->yscale) - mlx->zoom_y);
		}
		light_julia(mlx);
	}
	return (0);
}

void	handle_key_event(int keycode, t_display *mlx)
{
	if (keycode == 15)
		mlx->color->endr -= 100;
	else if (keycode == 5)
		mlx->color->endg -= 100;
	else if (keycode == 11)
		mlx->color->endb -= 100;
	else if (keycode == 17)
		mlx->color->endr += 100;
	else if (keycode == 4)
		mlx->color->endg += 100;
	else if (keycode == 45)
		mlx->color->endb += 100;
	else if (keycode == 124)
		mlx->zoom_x -= 20 * mlx->xscale;
	else if (keycode == 123)
		mlx->zoom_x += 20 * mlx->xscale;
	else if (keycode == 126)
		mlx->zoom_y += 20 * mlx->yscale;
	else if (keycode == 125)
		mlx->zoom_y -= 20 * mlx->yscale;
}

void	handle_mouse_event(int button, int x, int y, t_display *mlx)
{
	if (button == 5)
	{
		mlx->max_iter += 20;
		mlx->xscale *= 0.5;
		mlx->yscale *= 0.5;
		mlx->zoom_x = mlx->zoom_x - (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y - (y * mlx->yscale);
	}
	else if (button == 4)
	{
		mlx->max_iter -= 20;
		mlx->zoom_x = mlx->zoom_x + (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y + (y * mlx->yscale);
		mlx->yscale /= 0.5;
		mlx->xscale /= 0.5;
	}
}
