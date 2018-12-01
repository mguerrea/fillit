/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:54 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/08 14:45:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;
	char	*cpy;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len > s_len)
		return (NULL);
	if (!(result = (char*)malloc(len + 1)))
		return (NULL);
	cpy = result;
	s += start;
	while (len--)
		*cpy++ = *s++;
	*cpy = 0;
	return (result);
}
