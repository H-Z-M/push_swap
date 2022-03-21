/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:11:51 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 23:09:08 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define A 0
# define B 1

typedef enum e_op_list
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
}			t_op_list;

typedef struct s_option
{
	t_op_list		content;
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
	t_node	*top;
	t_node	*end;
}			t_stack;

/*
* init.c
*/
t_stack		*init_stack(void);
void		init_node(int ac, int *args, int *sorted, t_stack *stack);
t_stack		*init_push_swap(int ac, char **av, bool is_push_swap);

/*
* args_check.c
*/
int			*ft_atoi_ps(int ac, char **av, bool is_push_swap);

/*
* quick_sort.c
*/
void		quick_sort(int args[], int first, int last);

/*
* node_add.c
*/
t_node		*create_node(int data, int idx);
void		node_add_front(t_stack *stack, int data, int idx);
void		node_add_back(t_stack *stack, int data, int idx);

/*
* operate_swap.c
*/
void		sa(t_stack *stack[2], t_option **opt);
void		sb(t_stack *stack[2], t_option **opt);
void		ss(t_stack *stack[2], t_option **opt);

/*
* operate_push.c
*/
void		pa(t_stack *stack[2], t_option **opt);
void		pb(t_stack *stack[2], t_option **opt);

/*
* operate_rotate.c
*/
void		ra(t_stack *stack[2], t_option **opt);
void		rb(t_stack *stack[2], t_option **opt);
void		rr(t_stack *stack[2], t_option **opt);

/*
* operate_reverse_rotate.c
*/
void		rra(t_stack *stack[2], t_option **opt);
void		rrb(t_stack *stack[2], t_option **opt);
void		rrr(t_stack *stack[2], t_option **opt);

/*
* node_delete.c
*/
void		delete_top_node(t_stack *stack);
void		delete_end_node(t_stack *stack);

/*
* delete_one_node.c
*/
void		delete_one_node_idx(int idx, t_stack *stack);
void		delete_one_node_data(int data, t_stack *stack);

/*
* option.c
*/
t_option	*opt_create(t_op_list content);
void		opt_addback(t_option **opt, t_op_list content);
void		opt_print(t_option *opt);

/*
* libfts.c
*/
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
void		ft_putendl_fd(char *s, int fd);
void		exit_error_msg(char *msg);

#endif
