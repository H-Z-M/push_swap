/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:22:54 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/15 07:34:41 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	pa(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	if (a_stk== NULL || b_stk== NULL || b_stk->top == NULL)
		exit_error_msg("pa error : stack is NULL");
	node_add_front(a_stk, b_stk->top->data, b_stk->top->idx);
	delete_top_node(b_stk);
	opt_addback(opt, PA);
}

void	pb(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	if (a_stk== NULL || b_stk== NULL || a_stk->top == NULL)
		exit_error_msg("pb error : stack is NULL");
	node_add_front(b_stk, a_stk->top->data, a_stk->top->idx);
	delete_top_node(a_stk);
	opt_addback(opt, PB);
}
