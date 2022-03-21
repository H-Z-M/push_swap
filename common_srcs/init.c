/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:15:13 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 23:16:35 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_node(int ac, int *args, int *sorted, t_stack *stack)
{
	int	i;
	int	idx;

	i = 0;
	while (i < ac)
	{
		idx = 0;
		while (idx < ac)
		{
			if (args[i] == sorted[idx])
			{
				node_add_back(stack, args[i], idx);
				break ;
			}
			idx++;
		}
		i++;
	}
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		exit_error_msg("init_stack error: malloc");
	stack->top = NULL;
	stack->end = NULL;
	return (stack);
}

t_stack	*init_push_swap(int ac, char **av, bool is_push_swap)
{
	int		i;
	int		*origin;
	int		*sorted;
	t_stack	*a_stk;

	origin = ft_atoi_ps(ac, av + 1, is_push_swap);
	sorted = malloc(sizeof(int) * ac);
	if (sorted == NULL)
		exit_error_msg("main error : malloc");
	i = -1;
	while (++i < ac)
		sorted[i] = origin[i];
	quick_sort(sorted, 0, ac - 1);
	a_stk = init_stack();
	init_node(ac, origin, sorted, a_stk);
	free(origin);
	free(sorted);
	return (a_stk);
}
