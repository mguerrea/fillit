/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:47:26 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/01 18:27:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "functions.h"
#include "libft.h"
#include <stdlib.h>

/*int	get_coords(char *str, t_tetrimino *tetrimino, size_t i, ssize_t j)
{
	size_t	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == '#')
		{
			if (i > 2)
				return (-1);
			if (org.x == -1)
				set_pos(&org, k, j);
			else
				set_pos(&tetrimino->blocks[i++], k - org.x, j - org.y);
		}
		k++;
	}
}*/

void	get_coords(t_pos *org, t_pos *tetrimino, int k, int j)
{
	if (org->x == -1)
		set_pos(org, k, j);
	else
		set_pos(tetrimino, k - org->x, j - org->y);
}

int		parse_one_tetrimino(int fd, t_tetrimino *tetrimino)
{
	t_pos	org;
	char	*str;
	ssize_t	j;
	ssize_t	k;
	size_t	i;

	j = -1;
	org.x = -1;
	i = 0;
	while (++j < 4)
	{
		if (get_next_line(fd, &str) != 1 || ft_strlen(str) != 4)
			return (-1);
		k = -1;
		while (str[++k])
			if (str[k] == '#')
			{
				if (i > 3)
				{
						ft_putnbr(i);
					return (-1);
				}
				get_coords(&org, &tetrimino->blocks[i], k, j);
				i++;
				// if (org.x == -1)
					// set_pos(&org, k, j);
				// else
					// set_pos(&tetrimino->blocks[i++], k - org.x, j - org.y);
			}
		free(str);
	}
	ft_putnbr(i);
	return ((i == 4) ? 1 : -1);
}

int	parse_tetriminos(t_tetrimino **tetriminos, int fd)
{
	char	*str;
	size_t	i;
	int		result;

	i = 0;
	while (42)
	{
		if (i >= 26)
			return (-1);
		if ((result = parse_one_tetrimino(fd, &((*tetriminos)[i]))) != 1)
		{
			if (result == 0 && i < 26)
			{
				(*tetriminos)[i].letter = 0;
				return (i - 1);
			}
			return (-1);
		}
		(*tetriminos)[i].letter = 'A' + i;
		if (check_coordinates(&(*tetriminos)[i]) == 0)
			return (-1);
		if (get_next_line(fd, &str) == 0)
		{
			(*tetriminos)[i + 1].letter = 0;
			return (i);
		}
		if (ft_strlen(str) != 0)
		{
			free(str);
			return (-1);
		}
		free(str);
		i++;
	}
	return (-1);
}
