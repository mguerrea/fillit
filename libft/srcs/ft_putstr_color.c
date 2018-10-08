/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:19:29 by mguerrea          #+#    #+#             */
/*   Updated: 2018/08/30 17:19:30 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstr_color(char *str, char *color)
{
    if (ft_strcmp(color, "red") == 0)
		write(1, "\x1B[31m", 5);
	if (ft_strcmp(color, "blue") == 0)
		write(1, "\x1B[34m", 5);
	if (ft_strcmp(color, "green") == 0)
		write(1, "\x1B[32m", 5);
	if (ft_strcmp(color, "yellow") == 0)
		write(1, "\x1B[33m", 5);
	ft_putstr(str);
	write(1, "\x1B[0m", 4);
}