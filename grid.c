/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:53:47 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/02 15:29:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include "libft.h"

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
