/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:14:23 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 08:54:25 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common_srcs/common.h"

int		distance(int target, t_node *current, bool front, bool designation);
void	split_stack(t_stack *stack[2], t_option **opt, int loop, int target);
void	sort_3(t_stack *stack[2], t_option **opt);
void	sort_5(t_stack *stack[2], t_option **opt, int split_size);
void	sort_over_6(t_stack *stack[2], t_option **opt, int size);

#endif
