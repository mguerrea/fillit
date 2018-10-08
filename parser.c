/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:47:26 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/08 23:31:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tetrimino.h"
#include <stdlib.h>
#include "pos.h"
#include <stdio.h>

int	parse_tetriminos(t_tetrimino **tetriminos, int fd)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;
	t_pos	origin;
	t_pos	temp;
	
	i = 0;
	while (i < 26)
	{
		origin.x = -1;
		// printf("i: %zu\n", i);
		j = 0;
		while (j < 4)
		{
			// printf("j: %zu\n", j);
			if (!get_next_line(fd, &str) || ft_strlen(str) != 4)
				return (0);
			fprintf(stderr, "str: %s\n", str);
			k = 0;
			while (str[k])
			{
				if (str[k] == '#')
					if (origin.x == -1)
					{
						set_pos(&origin, k, j);
						fprintf(stderr, "origin x: %d\norigin y: %d\n", origin.x, origin.y);
					}
					else
					{
						set_pos(&temp, k - origin.x, j - origin.y);
						ft_lstaddback(&((*tetriminos)[i].blocks), ft_lstnew(&temp, sizeof(t_tetrimino)));
						fprintf(stderr, "list x: %d\nlist y: %d\n", temp.x, temp.y);
					}
				k++;
			}
			j++;
		}
		get_next_line(fd, &str);
		if (ft_strlen(str) != 0)
			return (0);
		i++;
	}
	return (1);
}
