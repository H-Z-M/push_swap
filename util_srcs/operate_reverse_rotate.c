/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:29:10 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/14 21:45:14 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	rra(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	(void)b_stk;
	if (a_stk->top == a_stk->end)
		exit_error_msg("rra errror : 1 stack");
	node_add_front(a_stk, a_stk->end->data, a_stk->end->idx);
	delete_end_node(a_stk);
	if (opt != NULL)
		opt_addback(opt, RRA);
}

void	rrb(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	(void)a_stk;
	if (b_stk->top == b_stk->end)
		exit_error_msg("rrb errror : 1 stack");
	node_add_front(b_stk, b_stk->end->data, b_stk->end->idx);
	delete_end_node(b_stk);
	if (opt != NULL)
		opt_addback(opt, RRB);
}

void	rrr(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	rra(a_stk, b_stk, opt);
	rrb(a_stk, b_stk, opt);
	opt_addback(opt, RRR);
}
