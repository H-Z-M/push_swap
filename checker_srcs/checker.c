/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:35 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/16 22:31:18 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "checker.h" */
/* #include "push_swap.h" */
#include "../includes/push_swap.h"
#include "../includes/checker.h"

int	cmd_check(char *ac_cmd)
{
	int				i;
	const size_t	ex_cmd_len[12] = {3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4};
	const char		*ex_cmd[12] = {"sa\n", "sb\n", "ss\n",
	"pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	i = 0;
	while (i < 11)
	{
		if (ft_strlen(ac_cmd) == ex_cmd_len[i]
			&& !ft_strncmp(ac_cmd, ex_cmd[i], ex_cmd_len[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	exec_cmd(t_stack *a_stk, t_stack *b_stk)
{
	int					i;
	char				*cmd;
	const t_cmd_func	cmd_func[12] =
	{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	i = 0;
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			return ;
		i = cmd_check(cmd);
		if (i == -1)
		{
			delete_stack(a_stk);
			delete_stack(b_stk);
			free(cmd);
			exit_error_msg("ERROR");
		}
		cmd_func[i](a_stk, b_stk);
		free(cmd);
	}
}

void	checker(int ac, int *args, int *sorted)
{
	size_t	i;
	t_node	*p;
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = init_stack();
	init_node(ac, args, sorted, a_stk);
	free(args);
	free(sorted);
	b_stk = init_stack();
	exec_cmd(a_stk, b_stk);
	i = 0;
	p = a_stk->top;
	while (p && i++ == p->idx)
		p = p->next;
	if (i == (size_t)ac)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	delete_stack(a_stk);
	delete_stack(b_stk);
}
    /*  */
	/* print_stack(a_stk); */
	/* printf("\n"); */
	/* print_stack(b_stk); */
	/* printf("\n"); */


int	main(int ac, char **av)
{
	int		i;
	int		*args;
	int		*sorted;

	ac--;
	args = ft_atoi_ps(ac, av + 1);
	sorted = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		sorted[i] = args[i];
	quick_sort(sorted, 0, ac - 1);

	i = -1;
	while (++i < ac)
		printf("%d ", args[i]);
	printf("\n");
	i = -1;
	while (++i < ac)
		printf("%d ", sorted[i]);
	printf("\n");

	checker(ac, args, sorted);

	ft_putendl_fd("\nMAIN FINISH", STDOUT_FILENO);
}
