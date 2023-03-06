/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:39:31 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*	Hook key codes	*/
int	key_hook(int keycode, t_fdf *fdf)
{
	t_fdf	*tmp;

	tmp = fdf;
	if (keycode == KEYCODE_PLUS)
		zoom(fdf, 2);
	if (keycode == KEYCODE_MINUS)
		zoom(fdf, 0.5);
	if (keycode == KEYCODE_LEFT)
		ft_event(fdf, &move_left);
	if (keycode == KEYCODE_RIGHT)
		ft_event(fdf, &move_right);
	if (keycode == KEYCODE_DOWN)
		ft_event(fdf, &move_down);
	if (keycode == KEYCODE_UP)
		ft_event(fdf, &move_up);
	key_hook2(keycode, fdf);
	return (0);
}

int	key_hook2(int keycode, t_fdf *fdf)
{
	t_fdf	*tmp;

	tmp = fdf;
	if (keycode == KEYCODE_ENTER)
		change_projection(fdf);
	if (keycode == KEYCODE_C)
		ft_event(fdf, &color_update);
	if (keycode == KEYCODE_ESC)
		exit_fdf(tmp);
	return (0);
}

/*
**	Refresh image when key is pressed and run function.
*/
void	ft_event(t_fdf *fdf, void (*f)(t_map ***, int, int, t_draw *))
{
	update_pixels(&fdf->map, fdf->draw, f);
	put_img(fdf);
}
