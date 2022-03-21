/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:22:54 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 09:37:58 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_stack *stack[2], t_option **opt)
{
	if (stack[A] == NULL || stack[B] == NULL || stack[B]->top == NULL)
		return ;
	node_add_front(stack[A], stack[B]->top->data, stack[B]->top->idx);
	delete_top_node(stack[B]);
	if (opt != NULL)
		opt_addback(opt, PA);
}

void	pb(t_stack *stack[2], t_option **opt)
{
	if (stack[A] == NULL || stack[B] == NULL || stack[A]->top == NULL)
		return ;
	node_add_front(stack[B], stack[A]->top->data, stack[A]->top->idx);
	delete_top_node(stack[A]);
	if (opt != NULL)
		opt_addback(opt, PB);
}
