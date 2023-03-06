/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/16 16:21:00 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Draws a line between two points in a given color.
*/
void	ft_line_bresenham(t_img *img, t_point a, t_point b, int color)
{
	t_bres	bres;

	bres.deltaX = ft_abs(b.x - a.x);
	bres.slopeX = ft_sign(a.x, b.x);
	bres.deltaY = -ft_abs(b.y - a.y);
	bres.slopeY = ft_sign(a.y, b.y);
	bres.err = bres.deltaX + bres.deltaY;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(img, a, color);
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.deltaY)
		{
			bres.err += bres.deltaY;
			a.x += bres.slopeX;
		}
		if (bres.e2 <= bres.deltaX)
		{
			bres.err += bres.deltaX;
			a.y += bres.slopeY;
		}
	}
}

/*
**	Get sign of X,Y (used for slope)
*/
int	ft_sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
	return (0);
}

/*
**	Draws a line using the bresenham formula between two maps.
**	If error margin is greater than the delta Y increase x
**	otherwise increase y.
*/
void	ft_line_bresenham_map(t_img *img, t_map a, t_map b)
{
	t_bres	bres;
	t_map	i;

	i = a;
	bres.deltaX = ft_abs(b.pix_x - i.pix_x);
	bres.slopeX = ft_sign(i.pix_x, b.pix_x);
	bres.deltaY = -ft_abs(b.pix_y - i.pix_y);
	bres.slopeY = ft_sign(i.pix_y, b.pix_y);
	bres.err = bres.deltaX + bres.deltaY;
	while (i.pix_x != b.pix_x || i.pix_y != b.pix_y)
	{
		put_pixel(img, ft_point(i.pix_x, i.pix_y), color_fade(a, b, i));
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.deltaY)
		{
			bres.err += bres.deltaY;
			i.pix_x += bres.slopeX;
		}
		if (bres.e2 <= bres.deltaX)
		{
			bres.err += bres.deltaX;
			i.pix_y += bres.slopeY;
		}
	}
}
