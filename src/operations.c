/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:26:31 by username          #+#    #+#             */
/*   Updated: 2025/01/22 03:40:34 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->a)
		return ;
	if (!vars->b)
	{
		vars->b = vars->a;
		vars->a = vars->a->next;
		vars->b->next = NULL;
	}
	else if (get_stack_size(vars->a) == 1)
	{
		vars->a->next = vars->b;
		vars->b = vars->a;
		vars->a = NULL;
	}
	else
	{
		tmp = vars->a;
		vars->a = vars->a->next;
		tmp->next = vars->b;
		vars->b = tmp;
	}
	return (ad_op(PB, vars->ops), update_indices(vars));
}

void	pa(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->b)
		return ;
	if (!vars->a)
	{
		vars->a = vars->b;
		vars->b = vars->b->next;
		vars->a->next = NULL;
	}
	else if (get_stack_size(vars->b) == 1)
	{
		vars->b->next = vars->a;
		vars->a = vars->b;
		vars->b = NULL;
	}
	else
	{
		tmp = vars->b;
		vars->b = vars->b->next;
		tmp->next = vars->a;
		vars->a = tmp;
	}
	return (ad_op(PA, vars->ops), update_indices(vars));
}

void	sa(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->a || get_stack_size(vars->a) < 2)
		return ;
	tmp = vars->a;
	vars->a = vars->a->next;
	tmp->next = vars->a->next;
	vars->a->next = tmp;
	ad_op(SA, vars->ops);
	update_indices(vars);
}

void	sb(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->b || get_stack_size(vars->b) < 2)
		return ;
	tmp = vars->b;
	vars->b = vars->b->next;
	tmp->next = vars->b->next;
	vars->b->next = tmp;
	ad_op(SB, vars->ops);
	update_indices(vars);
}

void	ss(s_vars *vars)
{
	sa(vars);
	sb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(SS, vars->ops);
	update_indices(vars);
}
