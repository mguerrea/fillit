/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:30:15 by mguerrea          #+#    #+#             */
/*   Updated: 2018/09/26 15:02:50 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_list_to_str(t_list *list)
{
    size_t size;
    t_list *temp;
    char    *str;

    temp = list;
    size = 0;
    while (temp)
    {
        size = size + temp->content_size - 1;
        temp = temp->next;
    }
    if(!(str = ft_strnew(size)))
        return (NULL);
    temp = list;
    while (temp)
    {
        str = ft_strcat(str, temp->content);
        temp = temp->next;
    }
    return (str);
}