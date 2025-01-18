/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:26:31 by username          #+#    #+#             */
/*   Updated: 2025/01/18 18:52:48 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ad_op(PB, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
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
	ad_op(PA, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
}

void	sa(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->a || get_stack_size(vars->a) < 2)
		return ;
	tmp = vars->a;
	vars->a = vars->a->next;
	vars->a->next = tmp;
	ad_op(SA, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
}


void	sb(s_vars *vars)
{
	s_stack	*tmp;

	if (!vars->b || get_stack_size(vars->b) < 2)
		return ;
	tmp = vars->b;
	vars->b = vars->b->next;
	vars->b->next = tmp;
	ad_op(SB, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
}


void	ss(s_vars *vars)
{
	sa(vars);
	sb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(SS, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);

}

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
	update_indices(vars->b);
	update_indices(vars->a);
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
	update_indices(vars->b);
	update_indices(vars->a);
}

void	rr(s_vars *vars)
{
	ra(vars);
	rb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(RR, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
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
	update_indices(vars->b);
	update_indices(vars->a);
}

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
	update_indices(vars->b);
	update_indices(vars->a);
}

void	rrr(s_vars *vars)
{
	rra(vars);
	rrb(vars);
	remove_op(vars->ops, get_last_op(vars->ops));
	remove_op(vars->ops, get_last_op(vars->ops));
	ad_op(RRR, vars->ops);
	update_indices(vars->b);
	update_indices(vars->a);
}

void	do_op(int n, s_vars *vars, void (*op)(s_vars *vars))
{
	while (--n >= 0)
	{
		op(vars);
	}
}
