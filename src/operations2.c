/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:38:10 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 03:40:26 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->a || get_stack_size(vars->a) == 1)
		return ;
	tmp = vars->a;
	vars->a = vars->a->next;
	get_last(vars->a)->next = tmp;
	tmp->next = NULL;
	ad_op(RA, vars->ops);
	update_indices(vars);
}

void	rb(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->b || get_stack_size(vars->b) == 1)
		return ;
	tmp = vars->b;
	vars->b = vars->b->next;
	get_last(vars->b)->next = tmp;
	tmp->next = NULL;
	ad_op(RB, vars->ops);
	update_indices(vars);
}

void	rr(s_vars *vars)
{
	ra(vars);
	rb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(RR, vars->ops);
	update_indices(vars);
}

void	rra(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->a || get_stack_size(vars->a) == 1)
		return ;
	tmp = get_last(vars->a);
	get_at_index(get_stack_size(vars->a) - 2, vars->a)->next = NULL;
	tmp->next = vars->a;
	vars->a = tmp;
	ad_op(RRA, vars->ops);
	update_indices(vars);
}
