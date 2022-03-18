/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:11:51 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/17 21:52:25 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# define INVALID_ARGUMENT 0xFFFFFFFF

#include <stdio.h>

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef enum e_oplist
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}			t_oplist;

typedef struct s_option
{
	t_oplist		content;
	struct s_option	*next;
}		t_option;

typedef struct s_node
{
	int				data;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*end;
}			t_stack;

/*
* init_stack_node.c
*/
t_stack	*init_stack(void);
void	init_node(int ac, int *args, int *sorted, t_stack *stack);

/*
* args_check.c
*/
int		*ft_atoi_ps(int ac, char **av);

/*
* quick_sort.c
*/
void	quick_sort(int args[], int first, int last);

/*
* node_add.c
*/
t_node	*create_node(int data, int idx);
void	node_add_front(t_stack *stack, int data, int idx);
void	node_add_back(t_stack* stack, int data, int idx);

/*
* operate_swap.c
*/
void	sa(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	sb(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	ss(t_stack *stack_a, t_stack *stack_b, t_option **opt);

/*
* operate_push.c
*/
void	pa(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	pb(t_stack *stack_a, t_stack *stack_b, t_option **opt);

/*
* operate_rotate.c
*/
void	ra(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	rb(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	rr(t_stack *stack_a, t_stack *stack_b, t_option **opt);

/*
* operate_rotate.c
*/
void	rra(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	rrb(t_stack *stack_a, t_stack *stack_b, t_option **opt);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_option **opt);

/*
* delete_stack_node.c
*/
void	delete_stack(t_stack *stack);
void	delete_top_node(t_stack *stack);
void	delete_end_node(t_stack *stack);

/*
* delete_one_node.c
*/
void	delete_one_node_idx(int idx, t_stack *stack);
void	delete_one_node_data(int data, t_stack *stack);
void	free_node(t_node *node, t_stack *stack);
/*
* util.c
*/
void	exit_error_msg(char *msg);
void	print_stack(t_stack *stack);
void	print_stack_ab(t_stack *stack_a, t_stack *b_stack);

/*
* option.c
*/
t_option	*opt_create(t_oplist content);
void		opt_addback(t_option **opt, t_oplist content);
void		opt_print(t_option *opt);

/*
* libfts.c
*/
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);

#endif
