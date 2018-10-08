/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:56:17 by mguerrea          #+#    #+#             */
/*   Updated: 2018/08/30 16:56:17 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *temp;
    size_t          i;

    temp = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (temp[i] == (unsigned char)c)
            return (&temp[i]);
        i++;
    }
    return (NULL);
}