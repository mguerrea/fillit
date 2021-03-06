/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:20:27 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/18 04:43:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (!(dst = (char*)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}
