/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:11:54 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/17 22:09:12 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	delete_top_node(t_stack *stack)
{
	t_node	*top_node;

	if (stack == NULL || stack->top == NULL)
			exit_error_msg("delete_end_node error");
	top_node = stack->top;
	if (stack->top->next == NULL)
	{
		stack->top = NULL;
		stack->end = NULL;
		free(top_node);
		//------------
		stack->size--;
		//------------
		return ;
	}
	stack->top = top_node->next;
	stack->top->prev = NULL;
	//------------
	stack->size--;
	//------------
	free(top_node);
}

void	delete_end_node(t_stack *stack)
{
	t_node	*end_node;

	if (stack == NULL || stack->top == NULL || stack->end == NULL)
			exit_error_msg("delete_end_node error");
	end_node = stack->end;
	if (stack->top->next == NULL)
	{
		stack->top = NULL;
		stack->end = NULL;
		free(end_node);
		//------------
		stack->size--;
		//------------
		return ;
	}
	if (stack->top->next == stack->end)
	{
		stack->end = stack->top;
		stack->top->next = NULL;
		stack->end->prev = NULL;
		//------------
		stack->size--;
		//------------
		free(end_node);
		return ;
	}
	stack->end = end_node->prev;
	stack->end->next = NULL;
	//------------
	stack->size--;
	//------------
	free(end_node);
}

void	delete_stack(t_stack *stack)
{
	t_node	*previous;
	t_node	*current;

	if (stack == NULL)
		exit_error_msg("delete_stack error");
	current = stack->top;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
		printf("|||||||||||---");
	}
	free(stack);
}
