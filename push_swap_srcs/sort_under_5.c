/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:27:41 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/19 16:07:48 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack[2], t_option **opt)
{
	if (stack[A]->top->idx < stack[A]->end->idx)
	{
		if (stack[A]->top->idx - stack[A]->top->next->idx == -1)
			;
		else if (stack[A]->top->idx < stack[A]->top->next->idx)
		{
			rra(stack, opt);
			sa(stack, opt);
		}
		else
			sa(stack, opt);
	}
	else
	{
		if (stack[A]->top->idx - stack[A]->top->next->idx == 2)
			ra(stack, opt);
		else if (stack[A]->top->idx > stack[A]->top->next->idx)
		{
			ra(stack, opt);
			sa(stack, opt);
		}
		else
			rra(stack, opt);
	}
}

void	sort_5(t_stack *stack[2], t_option **opt, int split_size)
{
	int			i;
	t_option	*tmp;

	split_stack(stack, opt, split_size, split_size);
	sort_3(stack, opt);
	if (split_size >= 2 && stack[B]->top->idx < stack[B]->top->next->idx)
	{
		tmp = *opt;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->content == RA)
			rb(stack, opt);
		else if (tmp->content == RRA)
			rrb(stack, opt);
		else
			sb(stack, opt);
	}
	i = -1;
	while (++i < split_size)
		pa(stack, opt);
}
