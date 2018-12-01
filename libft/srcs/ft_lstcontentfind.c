/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentfind.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:16:37 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/19 11:24:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcontentfind(const t_list *lst, const void *to_find,
	size_t to_find_size)
{
	if (to_find)
		while (lst)
		{
			if (ft_memcmp(lst->content, to_find, ft_min(lst->content_size,
					to_find_size)) == 0)
				return ((t_list*)lst);
			lst = lst->next;
		}
	return (NULL);
}
