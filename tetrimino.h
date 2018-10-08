/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:24:41 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/08 23:14:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

#include "libft.h"

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

#endif
