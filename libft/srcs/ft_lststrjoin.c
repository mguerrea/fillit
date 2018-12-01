/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:00:21 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/09 13:19:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_makestr(const t_list *lst, const char *separator, char **str)
{
	if (lst && separator && str && *str)
		while (lst)
		{
			ft_strcat(*str, (char*)lst->content);
			if (lst->next)
				ft_strcat(*str, separator);
			lst = lst->next;
		}
}

char		*ft_lststrjoin(const t_list *lst, const char *separator)
{
	t_list	*cpy;
	size_t	str_len;
	size_t	separator_len;
	char	*result;

	if (!lst || !separator)
		return (NULL);
	cpy = (t_list*)lst;
	str_len = 0;
	separator_len = ft_strlen(separator);
	while (cpy)
	{
		str_len += cpy->content_size - 1;
		if (cpy->next)
			str_len += separator_len;
		cpy = cpy->next;
	}
	if (!(result = (char*)malloc(str_len + 1)))
		return (NULL);
	ft_makestr(lst, separator, &result);
	return (result);
}
