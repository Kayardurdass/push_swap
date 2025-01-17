/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:14 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/17 01:19:57 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


void	update_indices(s_stack *stack)
{
	int	i;
	s_stack	*current;

	i = 0;
	if (!stack)
		return ;
	current = stack;
	while (current->next != stack) {
		current->index = i;
		current = current->next;
		i++;
	}
	current->index = i;
}

void	push_to_stack(s_stack **stack_a, s_stack **stack_b)
{
	s_stack	*last_a;
	s_stack	*last_b;
	s_stack	*a;
	s_stack	*b;

	a = *stack_a;
	b = *stack_b;
	last_a = a->prev;
	last_b = b->prev;
	last_a->next = a->next;
	a->next->prev = last_a;
	last_b->next = a;
	b->next->prev = a;
	a->prev = last_b;
	a->next = b;
	*stack_a = last_a->next;
	*stack_b = last_b->next;
}

void	pb(s_vars *vars)
{
	s_stack	*last_b;
	s_stack	*b;
	s_stack *tmp;

	if (!vars->b)
		return ;
	if (stack_size(vars->b) == 1)
	{
		tmp = vars->a;
		tmp->prev->next = vars->b;
		tmp->next->prev = vars->b;
		vars->b->next = tmp;
		vars->b->prev = tmp->prev;
		vars->a = vars->a;
		vars->b = NULL;
		update_indices(vars->a);
		ad_op(PB, vars->ops);
		return ;
	}
	if (!vars->a)
	{
		tmp = vars->b;
		b = vars->b;
		last_b = b->prev;
		last_b->next = b->next;
		b->next->prev = last_b;
		vars->b = last_b->next;
		vars->a = tmp;
		tmp->prev = tmp;
		tmp->next = tmp;
		update_indices(vars->a);
		update_indices(vars->b);
		ad_op(PB, vars->ops);
		return ;
	}
	push_to_stack(&vars->b, &vars->a);
	update_indices(vars->a);
	update_indices(vars->b);
	ad_op(PB, vars->ops);
}

void	pa(s_vars *vars)
{
	s_stack	*last_a;
	s_stack	*a;
	s_stack	*tmp;

	if (!vars->a)
		return ;
	if (stack_size(vars->a) == 1)
	{
		tmp = vars->b;
		tmp->prev->next = vars->a;
		tmp->next->prev = vars->a;
		vars->a->next = tmp;
		vars->a->prev = tmp->prev;
		vars->b = vars->a;
		vars->a = NULL;
		ad_op(PA, vars->ops);
		return ;
	}
	if (!vars->b)
	{
		tmp = vars->a;
		a = vars->a;
		last_a = a->prev;
		last_a->next = a->next;
		a->next->prev = last_a;
		vars->a = last_a->next;
		tmp->next = tmp;
		tmp->prev = tmp;
		vars->b = tmp;
		update_indices(vars->a);
		update_indices(vars->b);
		ad_op(PA, vars->ops);
		return ;
	}
	push_to_stack(&vars->a, &vars->b);
	update_indices(vars->a);
	update_indices(vars->b);
	ad_op(PA, vars->ops);
}

void	sb(s_vars *vars)
{
	s_stack	*prev;
	s_stack	*next;
	s_stack	*a_1;
	s_stack	*a_2;

	if (!vars->b || stack_size(vars->b) == 1)
		return ;
	if (stack_size(vars->b) == 2)
	{
		vars->b = vars->b->next;
		update_indices(vars->b);
		ad_op(SB, vars->ops);
		return ;
	}
	prev = vars->b->prev;
	next = vars->b->next->next;
	a_1 = vars->b;
	a_2 = vars->b->next;
	prev->next = a_2;
	next->prev = a_1;
	a_1->prev = a_2;
	a_1->next = next;
	a_2->prev = prev;
	a_2->next = a_1;
	vars->b = a_2;
	update_indices(vars->b);
	ad_op(SB, vars->ops);
}

void	sa(s_vars *vars)
{
	s_stack	*prev;
	s_stack	*next;
	s_stack	*a_1;
	s_stack	*a_2;

	if (!vars->a || stack_size(vars->a) == 1)
		return ;
	if (stack_size(vars->a) == 2)
	{
		vars->a = vars->a->next;
		update_indices(vars->a);
		ad_op(SA, vars->ops);
		return ;
	}
	prev =  vars->a->prev;
	next = vars->a->next->next;
	a_1 = vars->a;
	a_2 = vars->a->next;
	prev->next = a_2;
	next->prev = a_1;
	a_1->prev = a_2;
	a_1->next = next;
	a_2->prev = prev;
	a_2->next = a_1;
	vars->a = a_2;
	update_indices(vars->a);
	ad_op(SA, vars->ops);
}

void	ss(s_vars *vars)
{
	sa(vars);
	sb(vars);
	ad_op(SS, vars->ops);
}

void	ra(s_vars *vars)
{
	if (!vars->a)
		return ;
	vars->a = vars->a->next;
	update_indices(vars->a);
	ad_op(RA, vars->ops);
}

void	rb(s_vars *vars)
{
	if (!vars->b)
		return ;
	vars->b = vars->b->next;
	update_indices(vars->b);
	ad_op(RB, vars->ops);
}

void	rr(s_vars *vars)
{
	ra(vars);
	rb(vars);
}

void	rra(s_vars *vars)
{
	if (!vars->a)
		return ;
	vars->a = vars->a->prev;
	update_indices(vars->a);
	ad_op(RRA, vars->ops);
}

void	rrb(s_vars *vars)
{
	if (!vars->b)
		return ;
	vars->b = vars->b->prev;
	update_indices(vars->b);
	ad_op(RRB, vars->ops);
}

void	rrr(s_vars *vars)
{
	rra(vars);
	rrb(vars);
	ad_op(RRR, vars->ops);
}
