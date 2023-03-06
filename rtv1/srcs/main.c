/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:21:15 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/31 14:24:15 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

/*
**	Initializes SDL, prints error and exits out if it failed.
*/
void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		if ((sdl->wind = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, DWIDTH, DHEIGHT,
					SDL_WINDOW_SHOWN)))
			if ((sdl->rend = SDL_CreateRenderer(sdl->wind, -1,
						SDL_RENDERER_ACCELERATED)))
				return ;
	ft_putendl("Error in initializing SDL.");
	exit (0);
}

int	val_2(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i] == 1))
			i++;
		else
			ft_error("Input is not a digit.");
	}
	return (1);
}

/*
**	Gets camera data from file and frees the string.
*/
void	cam_data(t_sdl *sdl, char **str)
{
	int	i;

	i = -1;
	sdl->cam.pos.x = (double)(ft_atoi(str[1]));
	sdl->cam.pos.y = (double)(ft_atoi(str[2]));
	sdl->cam.pos.z = (double)(ft_atoi(str[3]));
	sdl->cam.rot.x = (double)(ft_atoi(str[4]));
	sdl->cam.rot.x = (double)(ft_atoi(str[5]));
	sdl->cam.rot.x = (double)(ft_atoi(str[6]));
	while (++i <= 6)
		free(str[i]);
	free(str);
}

/*
**	Prints error and exits.
*/
void	ft_error(char *str)
{
	ft_putendl(str);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_sdl		sdl;
	t_ray		ray;
	SDL_Event	event;

	init_sdl(&sdl);
	ft_parse(argv[1], &sdl);
	if (argc != 2 || !argv[1])
		ft_error("Wrong or invalid arguments.");
	ray.orig.x = sdl.cam.pos.x;
	ray.orig.y = sdl.cam.pos.y;
	ray.orig.z = sdl.cam.pos.y;
	raytrace_init(&sdl, &ray);
	SDL_RenderPresent(sdl.rend);
	while (1)
		while (SDL_PollEvent(&event))
			if ((SDL_QUIT == event.type || (SDL_KEYDOWN == event.type && \
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode)))
				exit(0);
	return (0);
}
