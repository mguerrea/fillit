/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:50:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 23:19:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*tetriminos;
	t_grid		*grid;
	t_pos		tested_pos;


	if (argc == 2)
	{
		if (!(tetriminos = ft_memalloc(sizeof(t_tetrimino) * 27)))
			return (0);
		fd = open(argv[1], O_RDONLY);
		parse_tetriminos(&tetriminos, fd);
		grid = create_grid(5); // TODO: Calculer la taille opti
		set_pos(&tested_pos, 0, 1);
		set_pos(&tested_pos, 0, 0);
		solve(grid, tested_pos, tetriminos);
		ft_putstr(grid->str);
	}
}
