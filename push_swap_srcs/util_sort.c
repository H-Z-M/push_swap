/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:30:28 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/19 16:40:35 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance(int target, t_node *current, bool front, bool designation)
{
	int	dist;

	dist = 0;
	while (current != NULL)
	{
		if (designation && current->idx == target)
			break ;
		if (!designation && current->idx < target)
			break ;
		if (front)
			current = current->next;
		else
			current = current->prev;
		dist++;
	}
	return (dist);
}

void	split_stack(t_stack *stack[2], t_option **opt, int loop, int target)
{
	int	i;
	int	dist_back;
	int	dist_front;

	i = 0;
	while (i < loop)
	{
		dist_front = distance(target, stack[A]->top, true, false);
		dist_back = 1 + distance(target, stack[A]->end, false, false);
		if (dist_front <= dist_back)
			while (dist_front-- && stack[A]->top->next != NULL)
				ra(stack, opt);
		else
			while (dist_back-- && stack[A]->top->next != NULL)
				rra(stack, opt);
		pb(stack, opt);
		i++;
	}
}
