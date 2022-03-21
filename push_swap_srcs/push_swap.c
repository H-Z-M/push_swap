/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:35 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/22 00:19:24 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stack[2], int size, t_option *opt)
{
	if (size == 2)
		sa(stack, &opt);
	else if (size == 3)
		sort_3(stack, &opt);
	else if (size == 4)
		sort_5(stack, &opt, 1);
	else if (size == 5)
		sort_5(stack, &opt, 2);
	else
		sort_over_6(stack, &opt, size);
	opt_print(opt);
	while (stack[A]->top)
		delete_top_node(stack[A]);
	free(stack[A]);
	while (stack[B]->top)
		delete_top_node(stack[B]);
	free(stack[B]);
}

int	main(int ac, char **av)
{
	t_stack	*a_stk;

	if (ac == 1)
		return (1);
	a_stk = init_push_swap(--ac, av, true);
	if (a_stk == NULL)
		return (1);
	solve((t_stack *[2]){a_stk, init_stack()}, ac, NULL);
	return (0);
}
