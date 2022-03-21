/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:04:47 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/08 10:24:36 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	list_clear(t_list **top, t_list *current)
{
	t_list	*tmp;

	if (*top == current)
		*top = current->next;
	else
	{
		tmp = *top;
		while (tmp->next != current)
			tmp = tmp->next;
		tmp->next = current->next;
	}
	free(current->save);
	free(current);
}

char	*isnewline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*top;
	char	*newstr;

	newstr = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!newstr)
		return (NULL);
	top = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (top);
}

char	*ft_strndup(const char *s, size_t n)
{
	int		len;
	char	*top;
	char	*newstr;
	size_t	slen;

	slen = ft_strlen_gnl(s);
	if (slen < n)
		len = slen;
	else
		len = n;
	newstr = malloc(len + 1);
	if (!newstr)
		return (NULL);
	top = newstr;
	while (len--)
		*newstr++ = *s++;
	*newstr = '\0';
	return (top);
}
