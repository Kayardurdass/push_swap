/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:42:40 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 04:46:47 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_to_top(s_stack *stack, s_stack *to_move, s_vars *vars,
		int wich_stack)
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

int	get_cost_to_top(s_stack *stack, s_stack *to_move)
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

s_stack	*get_best_place(s_stack *stack, s_stack *to_place, int order)
{
	s_stack	*current;
	s_stack	*ret;
	int		closest_fit;

	closest_fit = INT_MAX;
	current = stack;
	while (current != NULL)
	{
		if ((abs((int)(to_place->nbr - current->nbr)) < closest_fit
			&& to_place->nbr > current->nbr && !order)
			|| (abs((int)(to_place->nbr - current->nbr)) < closest_fit
				&& to_place->nbr < current->nbr && order))
		{
			ret = current;
			closest_fit = abs((int)(to_place->nbr - current->nbr));
		}
		current = current->next;
	}
	return (ret);
}
