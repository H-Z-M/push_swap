/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:04:36 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/25 11:25:11 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

# define CONTINUE 1
# define END      0
# define ERROR   -1

char	*get_next_line(int fd);
char	*gnl_isnewline(const char *s, int c);
char	*gnl_strndup(const char *s, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
void	safe_free(void *p);
size_t	gnl_strlen(const char *s);

typedef struct s_lst
{
	int				fd;
	char			*save;
	struct s_lst	*next;
}				t_lst;

#endif
