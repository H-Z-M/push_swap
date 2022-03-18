/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:18:52 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/12 01:28:25 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	sa(t_stack	*a_stk, t_stack *b_stk, t_option **opt)
{
	t_node	*p;
	t_node	*n;

	(void)b_stk;
	if (a_stk->top == NULL || a_stk->top->next == NULL)
		exit_error_msg("sa errror : stack is NULL");
	p = a_stk->top;
	n = a_stk->top->next;
	p->prev = n;
	p->next = n->next;
	n->prev = NULL;
	n->next = p;
	if (a_stk->top == a_stk->end)
		a_stk->end = p;
	a_stk->top = n;
	if (opt != NULL)
		opt_addback(opt, SA);
}

void	sb(t_stack	*a_stk, t_stack *b_stk, t_option **opt)
{
	t_node	*p;
	t_node	*n;

	(void)a_stk;
	if (b_stk->top == NULL || b_stk->top->next == NULL)
		exit_error_msg("sb errror : stack is NULL");
	p = b_stk->top;
	n = b_stk->top->next;
	p->prev = n;
	p->next = n->next;
	n->prev = NULL;
	n->next = p;
	if (b_stk->top == b_stk->end)
		b_stk->end = p;
	b_stk->top = n;
	if (opt != NULL)
		opt_addback(opt, SB);
}

void	ss(t_stack	*a_stk, t_stack *b_stk, t_option **opt)
{
	sa(a_stk, b_stk, NULL);
	sb(a_stk, b_stk, NULL);
	opt_addback(opt, SS);
}
