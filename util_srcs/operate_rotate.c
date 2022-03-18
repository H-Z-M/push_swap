/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:23:47 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/14 21:44:18 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	ra(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	(void)b_stk;
	if (a_stk->top == a_stk->end)
		exit_error_msg("ra errror : 1 stack");
	node_add_back(a_stk, a_stk->top->data, a_stk->top->idx);
	delete_top_node(a_stk);
	if (opt != NULL)
		opt_addback(opt, RA);
}

void	rb(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	(void)a_stk;
	if (b_stk->top == b_stk->end)
		exit_error_msg("rb errror : 1 stack");
	node_add_back(b_stk, b_stk->top->data, b_stk->top->idx);
	delete_top_node(b_stk);
	if (opt != NULL)
		opt_addback(opt, RB);
}

void	rr(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	ra(a_stk, b_stk, NULL);
	rb(a_stk, b_stk, NULL);
	opt_addback(opt, RR);
}
