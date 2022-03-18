/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:13:22 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/10 20:55:38 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

t_node	*create_node(int data, int idx)
{
	t_node *current;

	current = (t_node *)malloc(sizeof(t_node));
	if (current == NULL)
		exit_error_msg("create_node error: malloc");
	current->data = data;
	current->idx = idx;
	current->prev = NULL;
	current->next = NULL;
	return (current);
}

void	node_add_front(t_stack *stack, int data, int idx)
{
	t_node	*old_top;
	t_node	*new_node;

	if (stack == NULL)
		exit_error_msg("node_add_front error: stack is NULL");
	if (stack->top == NULL)
	{
		stack->top = create_node(data, idx);
		stack->end = stack->top;
		if (stack->top == NULL)
			exit_error_msg("node_add_front error: stack->top is NULL");
//-----------------------
		stack->size++;
//-----------------------
		return ;
	}
	old_top = stack->top;
	new_node = create_node(data, idx);
	if (new_node == NULL)
		exit_error_msg("node_add_front error: new_node is NULL");
	new_node->prev = NULL;
	new_node->next = old_top;
	old_top->prev = new_node;
	stack->top = new_node;

//-----------------------
	stack->size++;
//-----------------------
}

void	node_add_back(t_stack *stack, int data, int idx)
{
	t_node	*old_end;
	t_node	*new_node;

	if (stack == NULL)
		exit_error_msg("node_add_back error: stack is NULL");
	if (stack->top == NULL)
	{
		stack->top = create_node(data, idx);
		stack->end = stack->top;
		if (stack->top == NULL)
			exit_error_msg("node_add_back error: stack->top is NULL");
		//-----------------------
		stack->size++;
		//-----------------------
		return ;
	}
	old_end = stack->end;
	new_node = create_node(data, idx);
	if (new_node == NULL)
		exit_error_msg("node_add_back error: new_node is NULL");
	new_node->prev = old_end;
	new_node->next = NULL;
	old_end->next = new_node;
	stack->end = new_node;
//-----------------------
	stack->size++;
//-----------------------
}
