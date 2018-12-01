/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:38:44 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/18 04:19:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_cpy;

	s1_cpy = s1 + ft_strlen(s1);
	while (n-- && *s2)
		*(s1_cpy++) = *(s2++);
	*s1_cpy = 0;
	return (s1);
}
