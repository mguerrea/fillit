/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:47:26 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 23:11:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "functions.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	parse_one_tetrimino(int fd, t_tetrimino *tetrimino)
{
	t_pos	origin;
	t_pos	temp;
	char	*str;
	ssize_t	j;
	ssize_t	k;

	j = -1;
	origin.x = -1;
	while (++j < 4)
	{
		if (!get_next_line(fd, &str) || ft_strlen(str) != 4)
			return (0);
		k = -1;
		while (str[++k])
			if (str[k] == '#')
				if (origin.x == -1)
					set_pos(&origin, k, j);
				else
				{
					set_pos(&temp, k - origin.x, j - origin.y);
					ft_lstaddback(&(tetrimino->blocks),
						ft_lstnew(&temp, sizeof(t_tetrimino)));
				}
	}
	return (1);
}

int	parse_tetriminos(t_tetrimino **tetriminos, int fd)
{
	char	*str;
	ssize_t	i;

	i = -1;
	while (++i < 26)
	{
		if (!parse_one_tetrimino(fd, &((*tetriminos)[i])))
		{
			(*tetriminos)[i].letter = 0;
			return (1);
		}
		(*tetriminos)[i].letter = 'A' + i;
		get_next_line(fd, &str);
		if (ft_strlen(str) != 0)
			return (0);
	}
	(*tetriminos)[i].letter = 0;
	return (1);
}
