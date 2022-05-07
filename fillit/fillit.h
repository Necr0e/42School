/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/27 00:13:35 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

enum	e_returns
{
	success = 1,
	fail = 0,
	invalid_count = -1,
	invalid_chars = -2,
	invalid_mapsize = -3,
	missing_endl = -4,
	invalid_end = -5
};

typedef struct s_tuple
{
	int		x;
	int		y;
}			t_tuple;

typedef struct s_map
{
	char	**array;
}			t_map;

typedef struct s_etris
{
	t_tuple			coords[4];
	int				x_offset;
	int				y_offset;
	char			value;
	struct s_etris	*next;
}					t_etris;

void	free_map(t_map *map, int map_size);
void	solve(t_etris *piecelist, int piececount);
void	free_tlist(t_etris **tlist);
void	print_map(t_map *map, int size);

t_map	*new_map(int map_size);

int		parse_pieces(char *fname, t_etris **tlist);
int		charcount(char *s);
int		connectioncount(char *s);
int		round_up_sqrt(int n);

#endif