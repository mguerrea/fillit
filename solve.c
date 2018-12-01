/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:30:41 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/01 15:26:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		check_place(t_grid *grid, t_pos *pos, t_tetrimino *tetrimino)
{
	t_pos	origin;
	size_t	i;

	if (*get_char_at(pos, grid) != '.')
		return (0);
	i = 0;
	while (i < 3)
	{
		origin = *pos;
		origin.x += tetrimino->blocks[i].x;
		origin.y += tetrimino->blocks[i].y;
		if ((origin.x >= (int)grid->width || origin.y >= (int)grid->width) ||
			*get_char_at(&origin, grid) != '.')
			return (0);
		i++;
	}
	return (1);
}

void	place_tetrimino(t_grid *grid, t_tetrimino *tetrimino, t_pos *pos)
{
	t_pos	origin;
	size_t	i;

	i = 0;
	*get_char_at(pos, grid) = tetrimino->letter;
	while (i < 3)
	{
		origin = *pos;
		origin.x += tetrimino->blocks[i].x;
		origin.y += tetrimino->blocks[i].y;
		*get_char_at(&origin, grid) = tetrimino->letter;
		i++;
	}
}

void	delete_tetrimino(t_grid *grid, t_tetrimino *tetrimino, t_pos *pos)
{
	t_pos	origin;
	size_t	i;

	i = 0;
	while (*get_char_at(pos, grid) != tetrimino->letter)
		increment_pos(pos, grid);
	*get_char_at(pos, grid) = '.';
	while (i < 3)
	{
		origin = *pos;
		origin.x += tetrimino->blocks[i].x;
		origin.y += tetrimino->blocks[i].y;
		*get_char_at(&origin, grid) = '.';
		i++;
	}
}

int		solve(t_grid *grid, t_pos pos, t_tetrimino *list)
{
	while (!(pos.x == (int)grid->width - 1 && pos.y == (int)grid->width - 1))
	{
		if (check_place(grid, &pos, list))
		{
			place_tetrimino(grid, list, &pos);
			set_pos(&pos, 0, 0);
			if ((list + 1)->letter)
			{
				if (solve(grid, pos, list + 1))
					return (1);
			}
			else
				return (1);
			delete_tetrimino(grid, list, &pos);
		}
		increment_pos(&pos, grid);
	}
	return (0);
}
