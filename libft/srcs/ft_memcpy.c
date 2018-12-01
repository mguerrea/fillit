/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:49:53 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/17 03:42:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_u8		*dst_byte;
	const t_u8	*src_byte;

	dst_byte = (t_u8*)dst;
	src_byte = (const t_u8*)src;
	while (n--)
		*(dst_byte++) = *(src_byte++);
	return (dst);
}
