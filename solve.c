/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:30:41 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/17 16:46:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>

int	check_place(t_grid *grid, t_pos *pos, t_tetrimino *tetrimino)
{
	t_list	*blocks;
	t_pos	origin;
	int		i;

	if (*get_char_at(pos, grid) != '.')
		return (0);
	//printf("yolo\n");
	blocks = tetrimino->blocks;
	i = -1;
	while (++i < 3)
	{
		//printf("yolo %d\n", i);
		origin = *pos;
		//printf("%d %d\n", ((t_pos*)blocks->content)->x, ((t_pos*)blocks->content)->y);
		origin.x += ((t_pos*)blocks->content)->x;
		origin.y += ((t_pos*)blocks->content)->y;
		//printf("swag\n");
		printf("%d %d >= %d\n", origin.x, origin.y, grid->width);
		if ((origin.x >= grid->width || origin.y >= grid->width) ||
			*get_char_at(&origin, grid) != '.')
			return (0);
		blocks = blocks->next;
	}
	return (1);
}

int	solve(t_grid *grid, t_pos pos, t_tetrimino *list, char letter)
{

	return (0);
}
