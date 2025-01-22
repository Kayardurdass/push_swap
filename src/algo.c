/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:35:52 by username          #+#    #+#             */
/*   Updated: 2025/01/22 04:51:03 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve_3(s_vars *vars)
{
	long	first;
	long	second;
	long	last;

	first = vars->a->nbr;
	second = vars->a->next->nbr;
	last = vars->a->next->next->nbr;
	if (first < second && second < last)
		return ;
	if (first > second && first < last && second < last)
		sa(vars);
	else if (first > second && first > last && second < last)
		ra(vars);
	else if (first < second && first < last && second > last)
	{
		rra(vars);
		sa(vars);
	}
	else if (first < second && first > last && second > last)
		rra(vars);
	else
	{
		sa(vars);
		rra(vars);
	}
}

void	solve_2(s_vars *vars)
{
	if (vars->a->nbr > vars->a->next->nbr)
		sa(vars);
}

void	solve_5(s_vars *vars)
{
	get_to_top(vars->a, get_big(vars->a), vars, 0);
	pb(vars);
	get_to_top(vars->a, get_little(vars->a), vars, 0);
	pb(vars);
	solve_3(vars);
	pa(vars);
	pa(vars);
	ra(vars);
}

int	solve2(s_vars *vars)
{
	if (get_stack_size(vars->a) == 1 || is_sorted(vars))
		return (0);
	if (get_stack_size(vars->a) == 2)
		solve_2(vars);
	else if (get_stack_size(vars->a) == 3)
		solve_3(vars);
	else if (get_stack_size(vars->a) == 5)
		solve_5(vars);
	else
		return (1);
	return (0);
}

void	solve(s_vars *vars)
{
	if (solve2(vars))
	{
		do_op(2, vars, &pb);
		while (get_stack_size(vars->a) > 0)
		{
			if (get_next_nb_to_push(vars)->nbr > get_little(vars->b)->nbr)
			{
				get_to_top(vars->a, get_next_nb_to_push(vars), vars, 0);
				get_to_top(vars->b, get_best_place(vars->b, vars->a, 0), vars,
					1);
				pb(vars);
			}
			else
			{
				get_to_top(vars->a, get_next_nb_to_push(vars), vars, 0);
				get_to_top(vars->b, get_best_place(vars->b, vars->a, 1), vars,
					1);
				rb(vars);
				pb(vars);
			}
		}
		back_to_a(vars);
	}
}
