/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:37:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/08 20:18:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*result;
	size_t	nb_len;

	nb_len = ft_nblen(n);
	if (!(result = (char*)malloc(nb_len + 1)))
		return (NULL);
	result[nb_len] = 0;
	if (n < 0)
		result[0] = '-';
	while (42)
	{
		result[--nb_len] = '0' + ft_abs(n % 10);
		n /= 10;
		if (!n)
			break ;
	}
	return (result);
}
