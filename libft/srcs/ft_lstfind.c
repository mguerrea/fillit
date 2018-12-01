/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:30:30 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 18:21:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(const t_list *lst, const void *to_find,
	int (*cmp)(const void*, const void*))
{
	if (to_find && cmp)
		while (lst)
		{
			if (cmp(to_find, lst->content) == 0)
				return ((t_list*)lst);
			lst = lst->next;
		}
	return (NULL);
}
