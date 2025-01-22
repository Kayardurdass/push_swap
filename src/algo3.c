/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:47:48 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 04:49:51 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_next_nb_to_push2(t_vars *vars, t_stack *current, int *least_cost,
		t_stack **ret)
{
	if (current->nbr > get_big(vars->b)->nbr)
	{
		if (get_cost_to_top(vars->a, current) + get_cost_to_top(vars->b,
				get_big(vars->b)) < *least_cost)
		{
			*ret = current;
			*least_cost = get_cost_to_top(vars->a, current)
				+ get_cost_to_top(vars->b, get_big(vars->b));
		}
	}
	else if (current->nbr < get_little(vars->b)->nbr)
	{
		if (get_cost_to_top(vars->a, current) + get_cost_to_top(vars->b,
				get_little(vars->b)) < *least_cost)
		{
			*ret = current;
			*least_cost = get_cost_to_top(vars->a, current)
				+ get_cost_to_top(vars->b, get_big(vars->b));
		}
	}
	else
		return (1);
	return (0);
}

t_stack	*get_next_nb_to_push(t_vars *vars)
{
	t_stack	*current;
	t_stack	*ret;
	int		cost_to_top;
	int		total_cost;
	int		least_cost;

	current = vars->a;
	least_cost = INT_MAX;
	while (current != NULL)
	{
		if (get_next_nb_to_push2(vars, current, &least_cost, &ret))
		{
			cost_to_top = get_cost_to_top(vars->a, current);
			total_cost = cost_to_top + get_cost_to_top(vars->b,
					get_best_place(vars->b, current, 0));
			if (total_cost < least_cost)
			{
				ret = current;
				least_cost = total_cost;
			}
		}
		current = current->next;
	}
	return (ret);
}

void	back_to_a(t_vars *vars)
{
	get_to_top(vars->b, get_big(vars->b), vars, 1);
	do_op(get_stack_size(vars->b), vars, &pa);
}

int	is_sorted(t_vars *vars)
{
	t_stack	*current;

	current = vars->a;
	while (current)
	{
		if (current->next)
		{
			if (current->nbr > current->next->nbr)
				return (0);
		}
		current = current->next;
	}
	return (1);
}
