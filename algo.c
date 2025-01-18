/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:35:52 by username          #+#    #+#             */
/*   Updated: 2025/01/18 18:54:49 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_to_top(s_stack *stack, s_stack *to_move, s_vars *vars, int wich_stack)
{
	int	lst_size;

	if (!stack || !to_move)
		return ;
	lst_size = get_stack_size(stack);
	if (to_move->index < lst_size / 2)
	{
		if (wich_stack == 0)
			do_op(to_move->index, vars, &ra);
		else
			do_op(to_move->index, vars, &rb);
	}
	else
	{
		if (wich_stack == 0)
			do_op(get_stack_size(stack) - to_move->index, vars, &rra);
		else
			do_op(get_stack_size(stack) - to_move->index, vars, &rrb);
	}
}

s_stack	*get_little(s_stack *stack)
{
	long	least;
	s_stack	*ret;
	s_stack	*current;

	current = stack;
	least = LONG_MAX;
	while (current)
	{
		if (current->nbr < least)
		{
			ret = current;
			least = ret->nbr;
		}
		current = current->next;
	}
	return (ret);
}
s_stack	*get_big(s_stack *stack)
{
	long	most;
	s_stack	*ret;
	s_stack	*current;

	current = stack;
	most = LONG_MIN;
	while (current)
	{
		if (current->nbr > most)
		{
			ret = current;
			most = ret->nbr;
		}
		current = current->next;
	}
	return (ret);
}

void	solve(s_vars *vars)
{
	while (get_stack_size(vars->a) > 0)
	{
		get_to_top(vars->a, get_little(vars->a), vars, 0);
		pb(vars);
	}
	do_op(get_stack_size(vars->b), vars, &pa);
}
