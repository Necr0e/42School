/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:17:01 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/27 00:14:34 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_etris	**tlist;
	int		piececount;

	tlist = malloc(sizeof(t_etris));
	if (ac != 2)
	{
		ft_putendl("usage: fillit [input_file]");
		return (fail);
	}
	piececount = parse_pieces(av[1], tlist);
	if (!piececount)
	{
		ft_putendl("error");
		return (0);
	}
	solve(*tlist, piececount);
	free_tlist(tlist);
}
