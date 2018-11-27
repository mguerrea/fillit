/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:28:35 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 22:56:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "libft.h"

static int	is_adjacent(t_pos *a, t_pos *b, int *result)
{
	if ((ft_abs(a->x) == 1 && ft_abs(a->y) == 0) ||
		(ft_abs(a->y) == 1 && ft_abs(a->x) == 0))
		*result = 1;
	if ((!(ft_abs(a->x - b->x) == 1 && a->y - b->y == 0)) &&
		(!(ft_abs(a->y - b->y) == 1 && a->x - b->x == 0)) &&
		(!(ft_abs(b->x) == 1 && b->y == 0)) &&
		(!(ft_abs(b->y) == 1 && b->x == 0)))
		return (0);
	return (1);
}

int			check_coordinates(t_tetrimino *tetrimino)
{
	t_list	*blocks;
	t_list	*tmp;
	int		result;
	int		bool;

	blocks = tetrimino->blocks;
	result = 0;
	while (blocks)
	{
		bool = 0;
		tmp = tetrimino->blocks;
		while (tmp)
		{
			if (tmp == blocks)
				tmp = tmp->next;
			if (!tmp)
				break ;
			if (is_adjacent((t_pos*)tmp->content, (t_pos*)blocks->content,
				&result))
				bool = 1;
			tmp = tmp->next;
		}
		if (!bool)
			return (0);
		blocks = blocks->next;
	}
	return (result);
}
