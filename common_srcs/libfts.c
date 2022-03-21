/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:53:04 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 08:52:46 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	u1;
	unsigned char	u2;

	while (len--)
	{
		u1 = (unsigned char)*s1++;
		u2 = (unsigned char)*s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	exit_error_msg(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
