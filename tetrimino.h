/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:24:41 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/08 21:36:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

typedef struct	s_pos
{
	unsigned int	x;
	unsigned int	y;
}				t_pos;

typedef struct	s_tetrimino
{
	char	letter;
	t_pos	first_block;
	t_pos	second_block;
	t_pos	third_block;
}				t_tetrimino;

#endif
