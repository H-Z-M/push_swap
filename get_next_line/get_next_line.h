/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:04:36 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/08 10:25:00 by sudatsu          ###   ########.fr       */
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

typedef struct s_list
{
	int				fd;
	char			*save;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*isnewline(char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	list_clear(t_list **top, t_list *current);
size_t	ft_strlen_gnl(const char *s);

#endif
