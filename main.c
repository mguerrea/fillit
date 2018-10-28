/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:50:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/17 16:34:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*tetriminos;
	t_tetrimino	*cpy;
	t_grid		*grid;
	t_pos		tested_pos;

	if (argc == 2)
	{
		if (!(tetriminos = ft_memalloc(sizeof(t_tetrimino) * 26)))
			return (0);
		fd = open(argv[1], O_RDONLY);
		printf("%d\n", parse_tetriminos(&tetriminos, fd));
		cpy = tetriminos;
		while (cpy->blocks)
		{
			printf("%c %d %d, %d %d, %d %d\n", cpy->letter,
				((t_pos*)cpy->blocks->content)->x,
				((t_pos*)cpy->blocks->content)->y,
				((t_pos*)cpy->blocks->next->content)->x,
				((t_pos*)cpy->blocks->next->content)->y,
				((t_pos*)cpy->blocks->next->next->content)->x,
				((t_pos*)cpy->blocks->next->next->content)->y);
			cpy++;
		}
		grid = create_grid(5); // TODO: Calculer la taille opti
		printf("%s\n", grid->str);
		set_pos(&tested_pos, 0, 1);
		printf("%d\n", check_place(grid, &tested_pos, tetriminos));
	}
}
