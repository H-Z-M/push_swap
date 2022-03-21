/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:18:52 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 09:00:47 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_stack *stack[2], t_option **opt)
{
	int	d;
	int	i;

	if (stack[A]->top == NULL || stack[A]->top->next == NULL)
		return ;
	d = stack[A]->top->next->data;
	i = stack[A]->top->next->idx;
	delete_one_node_idx(stack[A]->top->next->idx, stack[A]);
	node_add_front(stack[A], d, i);
	if (opt != NULL)
		opt_addback(opt, SA);
}

void	sb(t_stack *stack[2], t_option **opt)
{
	int	d;
	int	i;

	if (stack[B]->top == NULL || stack[B]->top->next == NULL)
		return ;
	d = stack[B]->top->next->data;
	i = stack[B]->top->next->idx;
	delete_one_node_idx(stack[B]->top->next->idx, stack[B]);
	node_add_front(stack[B], d, i);
	if (opt != NULL)
		opt_addback(opt, SB);
}

void	ss(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top == NULL || stack[A]->top->next == NULL
		|| stack[B]->top == NULL || stack[B]->top->next == NULL)
		return ;
	sa(stack, NULL);
	sb(stack, NULL);
	if (opt != NULL)
		opt_addback(opt, SS);
}
