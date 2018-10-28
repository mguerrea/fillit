/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:23:18 by mguerrea          #+#    #+#             */
/*   Updated: 2018/10/16 23:41:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_pos *position(int index, int width)
{
    t_pos *pos;

    pos->x = index % (width + 1);
    pos->y = index / (width + 1);
    return (pos);
}

char *get_char_at(t_pos *pos, t_grid *grid)
{
    int index;

    index = pos->y * (grid->width + 1) + pos->x;
    return (&(grid->str[index]));
}

void	set_pos(t_pos *pos, unsigned int x, unsigned int y)
{
	pos->x = x;
	pos->y = y;
}
