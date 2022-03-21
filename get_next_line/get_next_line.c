/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:05:43 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/08 10:23:28 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	list_create(t_list **top, t_list **current, int fd)
{
	*current = malloc(sizeof(t_list));
	if (!*current)
		return (ERROR);
	(*current)->fd = fd;
	(*current)->save = ft_strndup("", 0);
	if (!*top)
		(*current)->next = NULL;
	else
		(*current)->next = *top;
	*top = *current;
	return (CONTINUE);
}

int	list_find(t_list **top, t_list **current, int fd)
{
	*current = *top;
	while (*current && (*current)->fd != fd)
		*current = (*current)->next;
	if (*current)
		return (CONTINUE);
	return (list_create(top, current, fd));
}

int	save_to_line(char *newline, char **save, char **line)
{
	char	*tmp;

	*line = ft_strndup(*save, newline - *save + 1);
	if (!*line)
		return (ERROR);
	tmp = ft_strndup(newline + 1, ft_strlen_gnl(newline + 1));
	if (!tmp)
		return (ERROR);
	free(*save);
	*save = tmp;
	return (CONTINUE);
}

int	read_to_newline(int fd, char **save, char *read_buf, char **line)
{
	char	*tmp;
	ssize_t	read_sz;

	while (1)
	{
		tmp = isnewline(*save);
		if (tmp)
			return (save_to_line(tmp, save, line));
		read_sz = read(fd, read_buf, BUFFER_SIZE);
		if (read_sz == -1)
			return (ERROR);
		else if (read_sz == 0)
			break ;
		read_buf[read_sz] = '\0';
		tmp = ft_strjoin(*save, read_buf);
		if (!tmp)
			return (ERROR);
		free(*save);
		*save = tmp;
	}
	if (**save == '\0')
		*line = NULL;
	else
		*line = ft_strndup(*save, ft_strlen_gnl(*save));
	return (END);
}

char	*get_next_line(int fd)
{
	static t_list	*top;
	t_list			*current;
	char			*line;
	char			*read_buf;
	int				stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buf || list_find(&top, &current, fd) == ERROR)
		return (NULL);
	stat = read_to_newline(fd, &current->save, read_buf, &line);
	free(read_buf);
	if (stat == END || stat == ERROR)
		list_clear(&top, current);
	if (stat == ERROR)
		return (NULL);
	return (line);
}
