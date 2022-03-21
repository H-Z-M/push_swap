/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_one_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:12:19 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 22:00:35 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_node(t_node *node, t_stack *stack)
{
	t_node	*previous;

	if (node->prev == NULL)
	{
		stack->top = node->next;
		stack->top->prev = NULL;
		free(node);
		return ;
	}
	if (node->next == NULL)
	{
		stack->end = node->prev;
		stack->end->next = NULL;
		free(node);
		return ;
	}
	previous = node->prev;
	if (node->next != NULL)
		node->next->prev = previous;
	previous->next = node->next;
	free(node);
}

void	delete_one_node_idx(int idx, t_stack *stack)
{
	t_node	*p;

	p = stack->top;
	while (p != NULL)
	{
		if (p->idx == idx)
		{
			free_node(p, stack);
			return ;
		}
		p = p->next;
	}
}

void	delete_one_node_data(int data, t_stack *stack)
{
	t_node	*p;

	p = stack->top;
	while (p != NULL)
	{
		if (p->data == data)
		{
			free_node(p, stack);
			return ;
		}
		p = p->next;
	}
}
