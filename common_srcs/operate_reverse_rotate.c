/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:29:10 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 09:02:15 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top == stack[A]->end)
		return ;
	node_add_front(stack[A], stack[A]->end->data, stack[A]->end->idx);
	delete_end_node(stack[A]);
	if (opt != NULL)
		opt_addback(opt, RRA);
}

void	rrb(t_stack *stack[2], t_option **opt)
{
	if (stack[B]->top == stack[B]->end)
		return ;
	node_add_front(stack[B], stack[B]->end->data, stack[B]->end->idx);
	delete_end_node(stack[B]);
	if (opt != NULL)
		opt_addback(opt, RRB);
}

void	rrr(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top == stack[A]->end
		|| stack[B]->top == stack[B]->end)
		return ;
	rra(stack, NULL);
	rrb(stack, NULL);
	if (opt != NULL)
		opt_addback(opt, RRR);
}
