/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:36:43 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/01 18:07:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	read_line(t_fd *fd, char (*buffer)[BUFF_SIZE + 1],
	char **line, char **chr)
{
	size_t	read_size;
	char	*tmp;

	while (!(*chr = ft_strchr((char*)*line, '\n')))
	{
		if ((read_size = read(fd->fd, *buffer, BUFF_SIZE)) == 0)
			return ;
		(*buffer)[read_size] = 0;
		tmp = *line;
		*line = ft_strjoin(*line, *buffer);
		free(tmp);
		if (*line == NULL)
			return ;
	}
}

static int	get_line(t_fd *fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*chr;

	*line = ft_strdup(fd->buffer);
	buffer[0] = 0;
	read_line(fd, &buffer, line, &chr);
	if (*line == NULL)
		return (ERROR);
	if (ft_strlen(buffer) == 0 && ft_strlen(*line) == 0)
	{
		free(*line);
		return (READ_FINISH);
	}
	if (chr)
	{
		ft_strcpy(fd->buffer, &chr[1]);
		chr[0] = 0;
	}
	else
		fd->buffer[0] = 0;
	return (LINE_READ);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*find;
	t_fd			new_fd;
	int				retval;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (ERROR);
	new_fd.fd = fd;
	new_fd.buffer[0] = 0;
	if (!fd_list)
	{
		if (!(fd_list = ft_lstnew(&new_fd, sizeof(t_fd))))
			return (ERROR);
		find = fd_list;
	}
	else if (!(find = ft_lstcontentfind(fd_list, &fd, sizeof(int))))
	{
		if (!(find = ft_lstnew(&new_fd, sizeof(t_fd))))
			return (ERROR);
		ft_lstadd(&fd_list, find);
	}
	if ((retval = get_line(find->content, line)) == 0)
		ft_lstremove(&fd_list, find);
	return (retval);
}
