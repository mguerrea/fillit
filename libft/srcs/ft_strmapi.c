/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:33:46 by mguerrea          #+#    #+#             */
/*   Updated: 2018/08/30 17:33:46 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = NULL;
    if (s)
    {
		if(!(str = ft_strnew(ft_strlen((char *)s))))
			return (NULL);
    	i = -1;
        while (++i < ft_strlen((char *)s))
            str[i] = f(i, s[i]);
    }
	return (str);
}