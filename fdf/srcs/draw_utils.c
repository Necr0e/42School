/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/16 15:31:33 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*	Draw pixel on a point	*/
void	put_pixel(t_img *img, t_point a, int color)
{
	char	*dst;

	if (a.x > 10 && a.x < (WIN_WIDTH - 10) && a.y > 10 && a.y < \
	(WIN_HEIGHT - 10))
	{
		dst = img->addr + (a.y * img->line_length + a.x * \
		(img->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

/*
**	Destryo previous image and then redraw image on screen.
*/
void	put_img(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img->image);
	fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img->image)
		exit_fdf(fdf);
	fdf->img->addr = mlx_get_data_addr(fdf->img->image, \
	&fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	draw_map(fdf->img, &fdf->map, fdf->draw);
	put_display(fdf->img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
	put_menu_txt(fdf);
}

/*	Draw menu background and frame	*/
void	put_display(t_img *img)
{
	put_background(img, ft_point(MENU_X0, MENU_Y0), \
	ft_point(MENU_X1, MENU_Y1), BLACK);
	put_frame(img, ft_point(MENU_X0, MENU_Y0), \
	ft_point(MENU_X1, MENU_Y1), WHITE);
}

/*
**	Draws the menu background
*/
void	put_background(t_img *img, t_point a, t_point b, int color)
{
	int	i;

	i = 0;
	while ((a.y + i) <= b.y)
	{
		ft_line_bresenham(img, ft_point(a.x, a.y + i), \
		ft_point(b.x, a.y + i), color);
		i++;
	}
}

/*
**	Draws the menu border
*/
void	put_frame(t_img *img, t_point a, t_point b, int color)
{
	ft_line_bresenham(img, a, ft_point(b.x, a.y), color);
	ft_line_bresenham(img, a, ft_point(a.x, b.y), color);
	ft_line_bresenham(img, b, ft_point(b.x, a.y), color);
	ft_line_bresenham(img, b, ft_point(a.x, b.y), color);
}
