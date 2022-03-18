/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:36:37 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/16 21:32:29 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/util.h"

void	opt_delete(t_option **opt)
{
	t_option	*tmp;

	while (*opt)
	{
		tmp = *opt;
		*opt = (*opt)->next;
		free(tmp);
	}
}

t_option	*opt_create(t_oplist content)
{
	t_option	*new_opt;

	new_opt = (t_option *)malloc(sizeof(t_option));
	if (!new_opt)
		exit_error_msg("opt_create error : malloc");
	new_opt->content = content;
	new_opt->next = NULL;
	return (new_opt);
}

void	opt_addback(t_option **opt, t_oplist content)
{
	t_option	*ptr;

	if (*opt)
	{
		ptr = *opt;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = opt_create(content);
	}
	else
		*opt = opt_create(content);
}

static bool	reduce(t_option **opt, t_oplist a, t_oplist b)
{
	if ((*opt)->next!= NULL &&
		(((*opt)->content == a && (*opt)->next->content == b) ||
		 ((*opt)->content == b && (*opt)->next->content == a)))
	{
		(*opt) = (*opt)->next;
		return (true);
	}
	return (false);
}

void	opt_print(t_option *opt)
{
	const char	opt_lst[][4] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	while (opt != NULL)
	{
		if (reduce(&opt, PA, PB))
			;
		else if (reduce(&opt, SA, SB))
			ft_putendl_fd("ss", 1);
		else if (reduce(&opt, RA, RB))
			ft_putendl_fd("rr", 1);
		else if (reduce(&opt, RRA, RRB))
			ft_putendl_fd("rrr", 1);
		else
			ft_putendl_fd((char *)opt_lst[opt->content], 1);
		opt = opt->next;
	}
	opt_delete(&opt);
}
