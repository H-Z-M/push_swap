/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:35 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/22 00:08:55 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	read_line_check(char *read_line)
{
	int				i;
	const size_t	opt_len[12] = {3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4};
	const char		*opt_str[12] = {"sa\n", "sb\n", "ss\n",
									"pa\n", "pb\n",
									"ra\n", "rb\n", "rr\n",
									"rra\n", "rrb\n", "rrr\n"};

	i = 0;
	while (i < 11)
	{
		if (ft_strlen(read_line) == opt_len[i]
			&& !ft_strncmp(read_line, opt_str[i], opt_len[i]))
			return (i);
		i++;
	}
	return (-1);
}

t_option	*store_option(t_option *opt, t_option *tmp)
{
	int		op_list_idx;
	char	*read_line;

	op_list_idx = 0;
	while (1)
	{
		read_line = get_next_line(0);
		if (read_line == NULL)
			break ;
		op_list_idx = read_line_check(read_line);
		free(read_line);
		if (op_list_idx == -1)
		{
			while (opt)
			{
				tmp = opt->next;
				free(opt);
				opt = tmp;
			}
			exit_error_msg("Error");
		}
		opt_addback(&opt, (t_op_list)op_list_idx);
	}
	return (opt);
}

void	is_stack_sorted(t_stack *stack[2])
{
	int		idx;
	bool	ok;

	idx = 0;
	ok = true;
	while (stack[A]->top)
	{
		if (stack[A]->top->idx != idx++)
			ok = false;
		delete_top_node(stack[A]);
	}
	free(stack[A]);
	while (stack[B]->top)
	{
		ok = false;
		delete_top_node(stack[B]);
	}
	free(stack[B]);
	if (ok)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

void	run_option(t_stack *stack[2], t_option *opt)
{
	t_option		*tmp;
	const t_op_func	op_func[] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	while (opt)
	{
		op_func[opt->content](stack, NULL);
		tmp = opt->next;
		free(opt);
		opt = tmp;
	}
	is_stack_sorted(stack);
}

int	main(int ac, char **av)
{
	t_stack		*a_stk;
	t_option	*opt;

	if (ac == 1)
		return (1);
	a_stk = init_push_swap(--ac, av, false);
	opt = store_option(NULL, NULL);
	if (opt == NULL)
	{
		is_stack_sorted((t_stack *[2]){a_stk, init_stack()});
		return (0);
	}
	run_option((t_stack *[2]){a_stk, init_stack()}, opt);
}
