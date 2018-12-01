/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:29:32 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/17 02:35:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dst_cpy;

	dst_cpy = dst;
	while (len--)
	{
		*(dst++) = *src;
		if (*src)
			src++;
	}
	return (dst_cpy);
}
