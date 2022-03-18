/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:35 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/17 22:13:44 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/util.h"

int	distance(int target, t_node *nd, bool front, bool target_designation)
{
	int	dist;

	dist = 0;
	while (nd != NULL)
	{
		if (target_designation && nd->idx == target)
			break ;
		if (!target_designation && nd->idx < target)
			break ;
		if (front)
			nd = nd->next;
		else
			nd = nd->prev;
		dist++;
	}
	return (dist);
}

void	sort_2(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	sa(a_stk, b_stk, opt);
}

void	sort_3(t_stack *a_stk, t_stack *b_stk, t_option **opt)
{
	if (a_stk->top->idx < a_stk->end->idx)
	{
		if (a_stk->top->idx - a_stk->top->next->idx == -1)
			;
		else if (a_stk->top->idx < a_stk->top->next->idx)
		{
			rra(a_stk, b_stk, opt);
			sa(a_stk, b_stk, opt);
		}
		else
			sa(a_stk, b_stk, opt);
	}
	else
	{
		if (a_stk->top->idx - a_stk->top->next->idx == 2)
			ra(a_stk, b_stk, opt);
		else if (a_stk->top->idx > a_stk->top->next->idx)
		{
			ra(a_stk, b_stk, opt);
			sa(a_stk, b_stk, opt);
		}
		else
			rra(a_stk, b_stk, opt);
	}
}

void	split_stack(t_stack *a_stk, t_stack *b_stk, t_option **opt, int loop_cnt, int target)
{
	int	i;
	int	dist_back;
	int	dist_front;

	i = 0;
	while (i < loop_cnt)
	{
		dist_front = distance(target, a_stk->top, true, false);
		dist_back = 1 + distance(target, a_stk->end, false, false);
		if (dist_front <= dist_back)
			while (dist_front-- && a_stk->top->next != NULL)
				ra(a_stk, b_stk, opt);
		else
			while (dist_back-- && a_stk->top->next != NULL)
				rra(a_stk, b_stk, opt);
		pb(a_stk, b_stk, opt);
		i++;
	}
}

void	sort_5(t_stack *a_stk, t_stack *b_stk, t_option **opt, int split_size)
{
	int			i;
	t_option	*tmp;

	split_stack(a_stk, b_stk, opt, split_size, split_size);
	sort_3(a_stk, b_stk, opt);
	if (split_size >= 2 && b_stk->top->idx < b_stk->top->next->idx)
	{
		tmp = *opt;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->content == RA)
			rb(a_stk, b_stk, opt);
		else if (tmp->content == RRA)
			rrb(a_stk, b_stk, opt);
		else
			sb(a_stk, b_stk, opt);
	}
	i = -1;
	while (++i < split_size)
		pa(a_stk, b_stk, opt);
}

void	solution(t_stack *a_stk, t_stack *b_stk, t_option **opt, int size)
{
	int	i;
	int	target;
	int	dist_back;
	int	dist_front;

	i = 0;
	while (i < size)
	{
		target = size - i - 1;
		dist_front = distance(target, b_stk->top, true, true);
		dist_back = 1 + distance(target, b_stk->end, false, true);
		if (dist_front <= dist_back)
			while (dist_front--)
				rb(a_stk, b_stk, opt);
		else
			while (dist_back--)
				rrb(a_stk, b_stk, opt);
		if (b_stk->top != NULL)
			pa(a_stk, b_stk, opt);
		i++;
	}
}

void	sort_over_6(t_stack *a_stk, t_stack *b_stk, t_option **opt, int size)
{
	int	i;
	int	target;
	int	loop_cnt;
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
			loop_cnt = size / split_size;
		else
			loop_cnt = size / split_size + size % split_size;
		split_stack(a_stk, b_stk, opt, loop_cnt, target);
	}
	solution(a_stk, b_stk, opt, size);
}

void	solve(t_stack *a_stk, t_stack *b_stk, int size)
{
	/* printf("stack A\n"); */
	/* print_stack(a_stk); */
	/* printf("\n"); */
	t_option	*opt;

	opt = NULL;
	if (size == 2)
		sort_2(a_stk, b_stk, &opt);
	else if (size == 3)
		sort_3(a_stk, b_stk, &opt);
	else if (size == 4)
		sort_5(a_stk, b_stk, &opt, 1);
	else if (size == 5)
		sort_5(a_stk, b_stk, &opt, 2);
	else
		sort_over_6(a_stk, b_stk, &opt, size);
	/* else if (size < 20) */
	/* 	sort_over_6(a_stk, b_stk, &opt, size, 2); */
	/* else if (size < 500) */
	/* 	sort_over_6(a_stk, b_stk, &opt, size, 5); */
	opt_print(opt);
	/* printf("stack A\n"); */
	/* print_stack(a_stk); */
	/* printf("\n"); */
	/* printf("stack B\n"); */
	/* print_stack(b_stk); */
	/* printf("\n"); */
	delete_stack(a_stk);
	delete_stack(b_stk);
}

/* #include "../leakdetect.h" */
int	main(int ac, char **av)
{
	/* leak_detect_init(); */
	int		i;
	int		*origin;
	int		*sorted;
	t_stack	*a_stk;

	origin = ft_atoi_ps(--ac, av + 1);
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
	solve(a_stk, init_stack(), ac);
	system("leaks push_swap");
	/* leak_detect_check(); */
	return 0;
}
