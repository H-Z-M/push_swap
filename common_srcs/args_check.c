/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:57:39 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 23:16:49 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	issorted(int *args, int c, bool is_push_swap)
{
	int	i;
	int	j;

	i = 0;
	while (i < c)
	{
		j = i;
		while (++j < c)
		{
			if (args[i] > args[j])
				return ;
		}
		i++;
	}
	if (is_push_swap)
	{
		free(args);
		exit(EXIT_FAILURE);
	}
}

void	isoverlap(int *args, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c)
	{
		j = i;
		while (++j < c)
		{
			if (args[i] == args[j])
			{
				free(args);
				exit_error_msg("Error");
			}
		}
		i++;
	}
}

int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n'
		|| str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

long	ft_accumulate(const char *s)
{
	int		i;
	int		neg;
	long	acc;

	while (ft_isspace(*s))
		s++;
	neg = 0;
	if (*s == '-' || *s == '+')
	{
		neg = *s == '-';
		s++;
	}
	i = 0;
	acc = 0;
	while (*s && i++ < 11)
	{
		if (!ft_isdigit(*s))
			return (0xFFFFFFFF);
		acc = 10 * acc + *s - '0';
		s++;
	}
	if (neg)
		acc = -acc;
	return (acc);
}

int	*ft_atoi_ps(int ac, char **av, bool is_push_swap)
{
	int		i;
	int		*args;
	long	acc;

	args = malloc(sizeof(int) * ac);
	if (args == NULL)
		exit_error_msg("ft_atoi_ps error : malloc");
	i = 0;
	while (i < ac)
	{
		acc = ft_accumulate(av[i]);
		if (acc <= INT_MAX && acc >= INT_MIN)
			args[i] = (int)acc;
		else
		{
			free(args);
			exit_error_msg("Error");
		}
		i++;
	}
	isoverlap(args, ac);
	issorted(args, ac, is_push_swap);
	return (args);
}
