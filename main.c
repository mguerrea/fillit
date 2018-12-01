/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:50:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/01 18:07:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"
#include <fcntl.h>

void	fillit(size_t grid_size, t_tetrimino *tetriminos)
{
	t_grid	*grid;
	t_pos	origin;

	while (42)
	{
		grid = create_grid(grid_size);
		set_pos(&origin, 0, 0);
		if (solve(grid, origin, tetriminos))
		{
			ft_putstr(grid->str);
			return ;
		}
		grid_size++;
		free(grid);
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*tetriminos;
	size_t		grid_size;
	int			result;

	if (argc == 2)
	{
		if (!(tetriminos = ft_memalloc(sizeof(t_tetrimino) * 27)))
			return (0);
		fd = open(argv[1], O_RDONLY);
		if ((result = parse_tetriminos(&tetriminos, fd)) == -1)
		{
			ft_putendl_fd("error", 1);
			return (0);
		}
		grid_size = ft_sqrt((result + 1) * 4);
		fillit(grid_size, tetriminos);
	}
}
