/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:30:41 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 21:04:48 by mguerrea         ###   ########.fr       */
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

void    place_tetrimino(t_grid *grid, t_tetrimino *tetrimino, t_pos *pos)
{
    t_list    *blocks;
    t_pos    origin;
    int        i;

    blocks = tetrimino->blocks;
    i = -1;
	*get_char_at(pos, grid) = tetrimino->letter;
    while (++i < 3)
    {
        origin = *pos;
        origin.x += ((t_pos*)blocks->content)->x;
        origin.y += ((t_pos*)blocks->content)->y;
        *get_char_at(&origin, grid) = tetrimino->letter;
        blocks = blocks->next;
    }
}


int    solve(t_grid *grid, t_pos pos, t_tetrimino *list)
{
    t_pos    next;

    next = pos;
    if (check_place(grid, &pos, list) == 1)
    {
        place_tetrimino(grid, list, &pos);
        printf("%s\n", grid->str);
        // solve(grid, 
    }
    // solve(grid, 
    return (0);
}


