/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:55:28 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/05 09:39:33 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	exit_error_msg(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
	{
		ft_putendl_fd("print_stack error", STDOUT_FILENO);
		return ;
	}
	current = stack->top;
	while (current)
	{
		printf("data %7d  ",current->data);
		printf("idx  %3d",current->idx);
		printf("\n");
		current = current->next;
	}
}
