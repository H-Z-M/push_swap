/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:05:43 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/26 08:55:38 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_lstfind(t_lst **list_top, t_lst **current, int fd)
{
	*current = *list_top;
	while (*current && (*current)->fd != fd)
		*current = (*current)->next;
	if (*current)
		return (CONTINUE);
	*current = (t_lst *)malloc(sizeof(t_lst));
	if (!*current)
		return (ERROR);
	(*current)->fd = fd;
	(*current)->save = gnl_strndup("", 0);
	if (!*list_top)
		(*current)->next = NULL;
	else
		(*current)->next = *list_top;
	*list_top = *current;
	return (CONTINUE);
}

void	gnl_lstclear(t_lst **list_top, t_lst *current)
{
	t_lst	*tmp;

	if (*list_top == current)
		*list_top = current->next;
	else
	{
		tmp = *list_top;
		while (tmp->next != current)
			tmp = tmp->next;
		tmp->next = current->next;
	}
	safe_free(current->save);
	safe_free(current);
}

int	save_to_line(char *isnewline, char **save, char **line)
{
	char	*tmp;

	if (isnewline)
	{
		*line = gnl_strndup(*save, isnewline - *save + 1);
		tmp = gnl_strndup(isnewline + 1, gnl_strlen(isnewline + 1));
		if (!*line || !tmp)
			return (ERROR);
		safe_free(*save);
		*save = tmp;
		return (CONTINUE);
	}
	if (**save == '\0')
		*line = NULL;
	else
		*line = gnl_strndup(*save, gnl_strlen(*save));
	return (END);
}

int	read_file(int fd, char **save, char *buf, char **line)
{
	char	*tmp;
	ssize_t	read_sz;

	while (1)
	{
		tmp = gnl_isnewline(*save, '\n');
		if (tmp)
			return (save_to_line(tmp, save, line));
		read_sz = read(fd, buf, BUFFER_SIZE);
		if (read_sz == 0)
			break ;
		else if (read_sz == -1)
			return (ERROR);
		buf[read_sz] = '\0';
		tmp = gnl_strjoin(*save, buf);
		if (!tmp)
			return (ERROR);
		safe_free(*save);
		*save = tmp;
	}
	return (save_to_line(tmp, save, line));
}

char	*get_next_line(int fd)
{
	static t_lst	*list_top;
	t_lst			*current;
	char			*line;
	char			*buf;
	int				stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf || gnl_lstfind(&list_top, &current, fd) == ERROR)
		return (NULL);
	stat = read_file(fd, &current->save, buf, &line);
	safe_free(buf);
	if (stat == END || stat == ERROR)
		gnl_lstclear(&list_top, current);
	if (stat == ERROR)
		return (NULL);
	return (line);
}
