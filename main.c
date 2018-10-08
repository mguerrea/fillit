/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:50:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/10/08 23:00:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tetrimino.h"
#include "parser.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	t_tetrimino	*tetriminos;

	if (argc == 2)
	{
		if (!(tetriminos = (t_tetrimino*)malloc(sizeof(t_tetrimino) * 26)))
			return (0);
		fd = open(argv[1], O_RDONLY);
		printf("%d\n", parse_tetriminos(&tetriminos, fd));
	}
}
