/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:43:36 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		exit(0);
	}
	init_mlx_and_img(&fdf);
	fdf.map = parse(argv[1], &fdf.draw->height, &fdf.draw->width);
	update_settings(&fdf);
	init_pixels(&fdf.map, fdf.draw);
	put_img(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, key_hook, &fdf);
	mlx_hook(fdf.win, 17, 1L << 2, exit_fdf, &fdf);
	ft_putstr_fd("Successfully reached end of program.\n", 2);
	mlx_loop(fdf.mlx);
	return (0);
}
