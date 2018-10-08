/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:17:57 by mguerrea          #+#    #+#             */
/*   Updated: 2018/10/08 23:05:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_elemdel(void *content, size_t content_size)
{
	(void)content_size;
    free(content);
    content = NULL;
    content_size = 0;
}
