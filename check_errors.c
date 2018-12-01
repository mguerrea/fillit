/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:28:35 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/01 18:07:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "libft.h"

static int	is_adjacent(t_pos a, t_pos b)
{
	if ((ft_abs(a.x - b.x) == 1 && a.y - b.y == 0) ||
		(ft_abs(a.y - b.y) == 1 && a.x - b.x == 0))
		return (1);
	return (0);
}

int			check_coordinates(t_tetrimino *tetrimino)
{
	size_t	i;
	size_t	j;
	size_t	count;
	t_pos	origin;

	i = 0;
	count = 0;
	while (i < 4)
	{
		set_pos(&origin, 0, 0);
		count += is_adjacent(origin, tetrimino->blocks[i]);
		j = 0;
		while (j < 4)
		{
			if (j == i)
				j++;
			if (j >= 3)
				break ;
			count += is_adjacent(tetrimino->blocks[i], tetrimino->blocks[j]);
			j++;
		}
		i++;
	}
	return (count >= 6);
}
