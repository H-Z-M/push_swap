/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:15:13 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/10 20:58:33 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	init_node(int ac, int *args, int *sorted, t_stack *stack)
{
	long	i;
	long	idx;

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

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit_error_msg("init_stack error: malloc");
	stack->size = 0;
	stack->top = NULL;
	stack->end = NULL;
	return (stack);
}
