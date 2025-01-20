/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:35:52 by username          #+#    #+#             */
/*   Updated: 2025/01/20 22:37:00 by uanglade         ###   ########.fr       */
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
			do_op(lst_size - to_move->index, vars, &rra);
		else
			do_op(lst_size - to_move->index, vars, &rrb);
	}
}

void	get_to_bottom(s_stack *stack, s_stack *to_move, s_vars *vars, int wich_stack)
{
	int	lst_size;

	if (!stack || !to_move)
		return ;
	lst_size = get_stack_size(stack);
	if (to_move->index < lst_size / 2)
	{
		if (wich_stack == 0)
			do_op(to_move->index, vars, &rra);
		else
			do_op(to_move->index, vars, &rrb);
	}
	else
	{
		if (wich_stack == 0)
			do_op(lst_size - to_move->index, vars, &ra);
		else
			do_op(lst_size - to_move->index, vars, &rb);
	}
}
int		get_cost_to_top(s_stack *stack, s_stack *to_move)
{
	int	lst_size;

	if (!stack || !to_move)
		return (0);
	lst_size = get_stack_size(stack);
	if (to_move->index < lst_size / 2)
		return (to_move->index);
	else
		return (lst_size - to_move->index);
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

s_stack	*get_best_place(s_stack	*stack, s_stack *to_place, int order)
{
	s_stack	*current;
	s_stack	*ret;
	int		closest_fit;

	closest_fit = INT_MAX;
	current = stack;
	while (current != NULL)
	{
		if (order == 0)
		{
			if (abs((int)(to_place->nbr - current->nbr)) < closest_fit && to_place->nbr > current->nbr)
			{
				ret = current;
				closest_fit = abs((int)(to_place->nbr - current->nbr));
			}
		}
		else
		{
			if (abs((int)(to_place->nbr - current->nbr)) < closest_fit && to_place->nbr < current->nbr)
			{
				ret = current;
				closest_fit = abs((int)(to_place->nbr - current->nbr));
			}
		}
		current = current->next;
	}
	return (ret);
}

s_stack	*get_next_nb_to_push(s_vars *vars)
{
	s_stack	*current;
	s_stack	*ret;
	int		cost_to_top;
	int		total_cost;
	int		least_cost;

	current = vars->a;
	least_cost = INT_MAX;
	while (current != NULL)
	{
		if (current->nbr > get_big(vars->b)->nbr)
		{
			cost_to_top = get_cost_to_top(vars->a, current);
			total_cost = cost_to_top + get_cost_to_top(vars->b, get_big(vars->b));
			if (total_cost < least_cost)
			{
				ret = current;
				least_cost = total_cost;
			}
		}
		else if (current->nbr < get_little(vars->b)->nbr)
		{
			cost_to_top = get_cost_to_top(vars->a, current);
			total_cost = cost_to_top + get_cost_to_top(vars->b, get_little(vars->b));
			if (total_cost < least_cost)
			{
				ret = current;
				least_cost = total_cost;
			}
		}
		else
		{
			cost_to_top = get_cost_to_top(vars->a, current);
			total_cost = cost_to_top + get_cost_to_top(vars->b, get_best_place(vars->b, current, 0));
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

void	solve(s_vars *vars)
{
	do_op(2, vars, &pb);
	while (get_stack_size(vars->a) > 3)
	{
		if (get_next_nb_to_push(vars)->nbr > get_little(vars->b)->nbr)
		{
			get_to_top(vars->a, get_next_nb_to_push(vars), vars, 0);
			get_to_top(vars->b, get_best_place(vars->b, vars->a, 0), vars, 1);
			pb(vars);
		}
		else
		{
			get_to_top(vars->a, get_next_nb_to_push(vars), vars, 0);
			get_to_top(vars->b, get_best_place(vars->b, vars->a, 1), vars, 1);
			rb(vars);
			pb(vars);
		}
	}	
}
