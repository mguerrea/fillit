/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 04:33:38 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/15 04:38:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstfree(t_list **list)
{
	t_list	*head;
	t_list	*next;

	if (list)
	{
		head = *list;
		while (head)
		{
			next = head->next;
			free(head->content);
			free(head);
			head = next;
		}
	}
}
