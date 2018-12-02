/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:47:26 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/02 15:27:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "functions.h"
#include "libft.h"
#include <stdlib.h>

int		get_coords(t_pos *org, t_pos *tetrimino, int k, int j)
{
	if (org->x == -1)
	{
		set_pos(org, k, j);
		return (0);
	}
	set_pos(tetrimino, k - org->x, j - org->y);
	return (1);
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
		if (get_next_line(fd, &str) != 1 || ft_strlen(str) != 4 || check_c(str))
			return (-1);
		k = -1;
		while (str[++k])
			if (str[k] == '#')
			{
				if (i > 3)
					return (-1);
				i += get_coords(&org, &tetrimino->blocks[i], k, j);
			}
		free(str);
	}
	return ((i == 3 && str[k] == '\0') ? 1 : -1);
}

int		check_tetrimino(int fd, t_tetrimino **tetriminos, size_t i)
{
	int	result;

	result = parse_one_tetrimino(fd, &((*tetriminos)[i]));
	if (result != 1)
	{
		if (result == 0 && i < 26)
		{
			(*tetriminos)[i].letter = 0;
			return (i - 1);
		}
		return (-1);
	}
	return (0);
}

int		check_next_line(int fd, t_tetrimino **tetriminos, size_t i)
{
	char	*str;

	if (get_next_line(fd, &str) == 0)
	{
		(*tetriminos)[i + 1].letter = 0;
		return (i + 1);
	}
	if (ft_strlen(str) != 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int		parse_tetriminos(t_tetrimino **tetriminos, int fd)
{
	size_t	i;
	int		result;

	i = 0;
	while (42)
	{
		if (i >= 26)
			return (-1);
		if ((result = check_tetrimino(fd, tetriminos, i)))
			return (result);
		(*tetriminos)[i].letter = 'A' + i;
		if (check_coordinates(&(*tetriminos)[i]) == 0)
			return (-1);
		if ((result = check_next_line(fd, tetriminos, i)))
			return (result - 1);
		i++;
	}
	return (-1);
}
