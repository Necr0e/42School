/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:27:55 by oseitama          #+#    #+#             */
/*   Updated: 2022/09/21 16:11:25 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_display	*mlx;

	if (ac == 2)
	{
		mlx = NULL;
		if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
			mandelbrot(mlx);
		else if (ft_strncmp(av[1], "julia", 6) == 0)
			julia(mlx);
		else if (ft_strncmp(av[1], "burning ship", 13) == 0)
			burningship(mlx);
		else
		{
			ft_putendl("Invalid fractol.  Valid options are: ");
			ft_putendl("Mandelbrot, Julia or Burning ship.");
		}
	}
	ft_putendl("Invalid input. enter a valid Fractol.");
	ft_putendl("Valid options are: Mandelbrot, Julia or Burning ship");
	return (0);
}
