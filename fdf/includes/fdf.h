/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/16 16:23:59 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*	Includes	*/
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <math.h>
# include <fcntl.h>

/*	Use math defines	*/
# define _USE_MATH_DEFINES

/*	Window and display	*/
# define WIN_NAME "FdF"
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1000
# define COLOR_INIT BLUE

/*	Defines the margin as Window width / 30	*/
# define MARGIN	60

/*
**	Defines for the menu
**	Menu point a bottom left and point b is
**	top right.
*/
# define MENU_WIDTH 405
# define MENU_HEIGHT 880
# define MENU_X0 60
# define MENU_Y0 60
# define MENU_X1 456
# define MENU_Y1 940

/*
**	The zone is the drawable zone.
*/
# define ZONE_WIDTH 1215
# define ZONE_HEIGHT 880
# define ZONE_X 525
# define ZONE_Y 60

/*
**	Perspective angle values.
**	30, and 45 * Pi respectively.
*/
# define ISOMETRIC 0.523599
# define CAVALIER 0.785398

/*	Colors	*/
# define BLACK (0x00000000)
# define WHITE (0x00FFFFFF)
# define RED (0x00FF0000)
# define GREEN (0x00008000)
# define YELLOW (0x00FFFF00)
# define BLUE (0x000000FF)

/*	Keycodes	*/
# define KEYCODE_C 8
# define KEYCODE_ENTER 36
# define KEYCODE_PLUS 34
# define KEYCODE_MINUS 31
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_DOWN 125
# define KEYCODE_UP 126
# define KEYCODE_ESC 53

# define MOVEMENT_STEP 100

/*	menu text	*/
# define MENU_COLOR WHITE
# define MENU_TXT "\n \
\nFDF ----------------------------\
\nThis project is about creating \
\na simplified 3D graphic \
\nrepresentation of a relief \
\nlandscape.\
\n \
\n \
\nBONUS OPTIONS ------------------\
\nZoom in               | 'i' \
\nZoom out              | 'o' \
\nMove                  | arrows \
\nChange projection     | 'Enter' \
\nChange colors         | 'c' \
\nQuit                  | 'ESC'"

/*	Structs	*/
typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_draw
{
	int		height;
	int		width;
	int		map_diag;
	int		scale_width;
	int		scale_height;
	int		scale;
	int		map_width;
	int		map_height;
	float	angle;
	int		projection;
	t_point	offset;
}				t_draw;

typedef struct s_map
{
	int		z;
	int		pix_x;
	int		pix_y;
	int		color;
}				t_map;

typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	**map;
	t_img	*img;
	t_draw	*draw;
}				t_fdf;

typedef struct s_bres
{
	int	deltax;
	int	slopex;
	int	deltay;
	int	slopey;
	int	err;
	int	e2;
}				t_bres;

/*	INITIALIZATION	*/
void	init_mlx_and_img(t_fdf *fdf);
void	init(t_fdf *fdf);
void	reset_to_default(t_fdf *fdf);
void	update_settings(t_fdf *fdf);

/*	PARSING	*/
int		word_counter(const char *line, const char chr);
void	get_mapdim(char *file_name, int *height, int *width);
t_map	**map_alloc(int height, int width);
void	put_value(t_map *row, char *line);
t_map	**map_create(char *file_name, int height, int width);
t_map	**parse(char *file_name, int *height, int *width);

/*	PIXEL MANIPULATION	*/
void	init_pixels(t_map ***map, t_draw *draw);
void	update_pixels(t_map ***map, t_draw *draw, \
void (*f)(t_map ***, int, int, t_draw *));
void	scale(t_map ***map, int x, int y, t_draw *draw);
void	projection(t_map ***map, int x, int y, t_draw *draw);
void	align_to_display(t_map ***map, int x, int y, t_draw *draw);

/*	BONUS	*/
void	zoom(t_fdf *fdf, float value);
void	change_projection(t_fdf *fdf);
void	color_update(t_map ***map, int x, int y, t_draw *draw);
void	reset_pixel(t_fdf *fdf);
void	move_up(t_map ***map, int x, int y, t_draw *draw);
void	move_down(t_map ***map, int x, int y, t_draw *draw);
void	move_left(t_map ***map, int x, int y, t_draw *draw);
void	move_right(t_map ***map, int x, int y, t_draw *draw);

/*	DRAW	*/
void	put_img(t_fdf *fdf);
void	draw_map(t_img *img, t_map ***map, t_draw *draw);
void	put_display(t_img *img);
void	put_background(t_img *img, t_point a, t_point b, int color);
void	put_frame(t_img *img, t_point a, t_point b, int color);
void	put_menu_txt(t_fdf *mlx);

/*	DRAW UTILS	*/
void	put_pixel(t_img *img, t_point a, int color);
int		ft_sign(int x, int y);

/*	Bresenham */
void	ft_line_bresenham_map(t_img *img, t_map a, t_map b);
void	ft_line_bresenham(t_img *img, t_point a, t_point b, int color);

/*	 COLORS	*/
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		color_fade(t_map a, t_map z, t_map i);
int		get_opposite_color(int color);

/*	EVENTS	*/
int		key_hook(int keycode, t_fdf *fdf);
int		key_hook2(int keycode, t_fdf *fdf);
void	ft_event(t_fdf *fdf, void (*f)(t_map ***, int, int, t_draw *));

/*	Points	*/
t_point	ft_point(int x, int y);
t_point	ft_pix_highest(t_map ***map, t_draw *draw);
t_point	ft_pix_leftest(t_map ***map, t_draw *draw);
t_point	ft_distance(t_map ***map, t_draw *draw);

/*	EXIT	*/
int		exit_fdf(t_fdf *fdf);
void	free_split(char **splitted);
void	map_free(t_map **map, int height);

#endif
