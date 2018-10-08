/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:23:18 by mguerrea          #+#    #+#             */
/*   Updated: 2018/10/08 23:01:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

t_pos *position(int index, int width)
{
    t_pos *pos;

    pos->x = index % (width + 1);
    pos->y = index / (width + 1);
    return (pos);
}

char *get_char_at(t_pos *pos, char *grid, int width)
{
    int index;

    index = pos->y * (width + 1) + pos->x;
    return (&grid[index]);
}

void	set_pos(t_pos *pos, unsigned int x, unsigned int y)
{
	pos->x = x;
	pos->y = y;
}
