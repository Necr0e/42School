/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:40:31 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/31 17:30:52 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	ambient_data(t_sdl *sdl, char **str)
{
	int	i;

	i = -1;
	sdl->ambient = (double)(ft_atoi(str[1])) / 100;
	if (sdl->ambient < 0)
		ft_error("Wrong intensity parameter.");
	while (++i <= 1)
		free(str[i]);
	free(str);
}

/*	Parse file storing the data	*/
void	split_parse(char **str, t_sdl *sdl)
{
	if (ft_strequ(str[0], "cam:"))
		cam_data(sdl, str);
	else if (ft_strequ(str[0], "sphere:"))
		sphere_data(sdl, str);
	else if (ft_strequ(str[0], "plane:"))
		plane_data(sdl, str);
	else if (ft_strequ(str[0], "cylinder:"))
		cylinder_data(sdl, str);
	else if (ft_strequ(str[0], "cone:"))
		cone_data(sdl, str);
	else if (ft_strequ(str[0], "light:"))
		light_data(sdl, str);
	else if (ft_strequ(str[0], "ambient:"))
		ambient_data(sdl, str);
}

void	ft_parse(char *arg, t_sdl *sdl)
{
	char	*line;
	int		fd;
	int		i;
	char	**spl_res;

	i = 0;
	fd = 0;
	line = NULL;
	sdl->obj_num = 0;
	sdl->light_num = 0;
	sdl->obj_counter = 0;
	sdl->light_counter = 0;
	validation_init(arg, sdl, fd, i);
	sdl->obj = ft_memalloc(sizeof(t_object) * sdl->obj_num);
	sdl->light = ft_memalloc(sizeof(t_object) * sdl->light_num);
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open file.");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		split_parse(spl_res, sdl);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
