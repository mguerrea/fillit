/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:45:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/14 09:49:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **list, t_list *new)
{
	t_list	*head;

	head = *list;
	while (head->next)
		head = head->next;
	head->next = new;
	return (head->next);
}
