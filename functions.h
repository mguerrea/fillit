/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:24:31 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 21:00:44 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "libft.h"

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_tetrimino
{
	char	letter;
	t_list	*blocks;
}				t_tetrimino;

typedef struct	s_grid
{
	char	*str;
	size_t	width;
}				t_grid;

int		parse_tetriminos(t_tetrimino **tetriminos, int fd);
void	set_pos(t_pos *pos, unsigned int x, unsigned int y);
char	*get_char_at(t_pos *pos, t_grid *grid);

t_grid	*create_grid(size_t width);

int		check_place(t_grid *grid, t_pos *pos, t_tetrimino *tetrimino);
int		solve(t_grid *grid, t_pos pos, t_tetrimino *list);

#endif
