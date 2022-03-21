/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:35 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/19 16:59:18 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution(t_stack *stack[2], t_option **opt, int size)
{
	int	i;
	int	target;
	int	dist_back;
	int	dist_front;

	i = 0;
	while (i < size)
	{
		target = size - i - 1;
		dist_front = distance(target, stack[B]->top, true, true);
		dist_back = 1 + distance(target, stack[B]->end, false, true);
		if (dist_front <= dist_back)
			while (dist_front--)
				rb(stack, opt);
		else
			while (dist_back--)
				rrb(stack, opt);
		if (stack[B]->top != NULL)
			pa(stack, opt);
		i++;
	}
}

void	sort_over_6(t_stack *stack[2], t_option **opt, int size)
{
	int	i;
	int	target;
	int	loop;
	int	split_size;

	if (size < 20)
		split_size = 2;
	else if (size < 500)
		split_size = 5;
	else
		split_size = 10;
	i = 0;
	while (++i <= split_size)
	{
		target = size / split_size * i;
		if (i != split_size)
			loop = size / split_size;
		else
			loop = size / split_size + size % split_size;
		split_stack(stack, opt, loop, target);
	}
	solution(stack, opt, size);
}
