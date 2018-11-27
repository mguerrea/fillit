/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:50:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 22:40:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*tetriminos;
	//t_tetrimino	*cpy;
	t_grid		*grid;
	t_pos		tested_pos;
	size_t		grid_size;
	int			result;

	if (argc == 2)
	{
		if (!(tetriminos = ft_memalloc(sizeof(t_tetrimino) * 27)))
			return (0);
		fd = open(argv[1], O_RDONLY);
		if ((result = parse_tetriminos(&tetriminos, fd)) == -1)
			return (0);
		grid_size = ft_sqrt(result * 4);
//		cpy = tetriminos;
	/*	while (cpy->blocks)
		{
			printf("%c %d %d, %d %d, %d %d\n", cpy->letter,
				((t_pos*)cpy->blocks->content)->x,
				((t_pos*)cpy->blocks->content)->y,
				((t_pos*)cpy->blocks->next->content)->x,
				((t_pos*)cpy->blocks->next->content)->y,
				((t_pos*)cpy->blocks->next->next->content)->x,
				((t_pos*)cpy->blocks->next->next->content)->y);
			cpy++;
		} */
		while (42)
		{
			grid = create_grid(grid_size);
			set_pos(&tested_pos, 0, 1);
			set_pos(&tested_pos, 0, 0);
		//	printf("%s\n", grid->str);
			if (solve(grid, tested_pos, tetriminos))
			{
				ft_putstr(grid->str);
				return (0);
			}
			grid_size++;
		}
	}
}
