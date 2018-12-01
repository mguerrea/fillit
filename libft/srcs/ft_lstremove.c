/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:11 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/19 11:39:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremove(t_list **list, t_list *to_remove)
{
	t_list	*before;
	t_list	*head;
	t_list	*after;

	if (list && *list)
	{
		before = NULL;
		head = *list;
		after = head->next;
		while (head && head != to_remove)
		{
			before = head;
			head = after;
			after = head->next;
		}
		if (before)
			before->next = after;
		else
			*list = after;
		free(head->content);
		free(head);
	}
}
