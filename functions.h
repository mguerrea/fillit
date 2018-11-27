/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:24:31 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 22:24:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

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

int				parse_tetriminos(t_tetrimino **tetriminos, int fd);
void			set_pos(t_pos *pos, unsigned int x, unsigned int y);
char			*get_char_at(t_pos *pos, t_grid *grid);
void			increment_pos(t_pos *pos, t_grid *grid);
void			decrement_pos(t_pos *pos, t_grid *grid);

t_grid			*create_grid(size_t width);

int				check_place(t_grid *grid, t_pos *pos, t_tetrimino *tetrimino);
int				solve(t_grid *grid, t_pos pos, t_tetrimino *list);

int				check_coordinates(t_tetrimino *tetrimino);

int				ft_sqrt(int nb);

#endif
