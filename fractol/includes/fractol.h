/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:18:03 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 16:11:08 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

# define SIDE 800

typedef struct		s_color
{
	unsigned char	r;
	int				startr;
	int				endr;
	unsigned char	g;
	int				startg;
	int				endg;
	unsigned char	b;
	int				startb;
	int				endb;
}					t_color;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_zoom
{
	int			x;
	int			y;
	double		scale;
	int			iter;
	int			max_iter;
}				t_zoom;

typedef struct	s_complex
{
	double		real;
	double		img;
}				t_complex;

typedef struct	s_display
{
	void		*init;
	void		*win;
	double		yscale;
	double		xscale;
	double		move_x;
	double		move_y;
	int			iter;
	int			max_iter;
	double		zoom_x;
	double		zoom_y;
	double		xcoord;
	double		ycoord;
	int			position;
	int			fractal;
	int			help_m;
	t_img		*img;
	t_color		*color;
}				t_display;

/*	Draw fractals		*/
void	mandelbrot(t_display *mlx);
void	julia(t_display *mlx);
void	burningship(t_display *mlx);
/*	Iterate fractals	*/
int	mandelbrot_iteration(t_complex z, int x, int y, t_display *mlx);
int	julia_iteration(t_complex c, int x, int y, t_display *mlx);
int	burningship_iteration(t_complex c, int x, int y, t_display *mlx);

/*	Light fractals		*/
void	light_mandelbrot(t_display *mlx);
void	light_julia(t_display *mlx);
void	light_burningship(t_display *mlx);

/*	Handle events		*/
int		key_event(int keycode, t_display *mlx);
int		mouse_event(int button, int x, int y, t_display *mlx);
int		mouse_coord(int x, int y, t_display *mlx);
void	handle_key_event(int keycode, t_display *mlx);
void	handle_mouse_event(int button, int x, int y, t_display *mlx);
int		error_event(t_display *mlx);

/*	Utilities			*/
void	help_menu(t_display *mlx);
void	draw_pixel(t_display *mlx, int x, int y, int color);
void	set_values(t_display *mlx);
int	handle_lighting_events(t_display *mlx);
t_display	*mlx_init(void);

/*	Color related functions */
char	*fill_color(char *r, char *g, char *b);
char	*dec_to_hex(unsigned int num);
int		ft_convertcolor(int red, int green, int blue);
int		color_pixels(t_display *mlx);
#endif
