/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:39:07 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 03:39:54 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrb(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->b || get_stack_size(vars->b) == 1)
		return ;
	tmp = get_last(vars->b);
	get_at_index(get_stack_size(vars->b) - 2, vars->b)->next = NULL;
	tmp->next = vars->b;
	vars->b = tmp;
	ad_op(RRB, vars->ops);
	update_indices(vars);
}

void	rrr(s_vars *vars)
{
	rra(vars);
	rrb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(RRR, vars->ops);
	update_indices(vars);
}

void	do_op(int n, s_vars *vars, void (*op)(s_vars *vars))
{
	while (--n >= 0)
		op(vars);
}
