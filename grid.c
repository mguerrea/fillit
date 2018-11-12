/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:53:47 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/12 15:47:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

t_grid	*create_grid(size_t width)
{
	t_grid	*grid;
	size_t	i;
	size_t	j;

	if (!(grid = (t_grid*)malloc(sizeof(t_grid))))
		return (NULL);
	grid->width = width;
	if (!(grid->str = ft_strnew((width + 1) * width)))
		return (NULL);
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < width)
		{
			grid->str[i * (width + 1) + j] = '.';
			j++;
		}
		grid->str[i * (width + 1) + j] = '\n';
		i++;
	}
	return (grid);
}
