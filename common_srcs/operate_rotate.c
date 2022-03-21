/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:23:47 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 22:00:51 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top == stack[A]->end)
		return ;
	node_add_back(stack[A], stack[A]->top->data, stack[A]->top->idx);
	delete_top_node(stack[A]);
	if (opt != NULL)
		opt_addback(opt, RA);
}

void	rb(t_stack *stack[2], t_option **opt)
{
	if (stack[B]->top == stack[B]->end)
		return ;
	node_add_back(stack[B], stack[B]->top->data, stack[B]->top->idx);
	delete_top_node(stack[B]);
	if (opt != NULL)
		opt_addback(opt, RB);
}

void	rr(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top == stack[A]->end
		|| stack[B]->top == stack[B]->end)
		return ;
	ra(stack, NULL);
	rb(stack, NULL);
	if (opt != NULL)
		opt_addback(opt, RR);
}
