/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:53:01 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/17 01:07:34 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_for_2(s_vars *vars)
{
	if (vars->a->nbr > vars->a->next->nbr)
	{
		sa(vars);
	}
}

void	solve_for_3(s_vars *vars)
{
	if (vars->a->nbr > vars->a->next->nbr && vars->a->nbr > vars->a->prev->nbr && vars->a->next->nbr < vars->a->prev->nbr) // 3 1 2
		ra(vars);
	else if (vars->a->nbr > vars->a->next->nbr && vars->a->prev->nbr > vars->a->nbr) // 2 1 3
		sa(vars);
	else if (vars->a->nbr > vars->a->next->nbr && vars->a->prev->nbr < vars->a->next->nbr) // 321
	{
		ra(vars);
		sa(vars);
	}
	else if (vars->a->nbr < vars->a->next->nbr && vars->a->prev->nbr < vars->a->next->nbr && vars->a->nbr > vars->a->prev->nbr) // 231 
		rra(vars);
	else if (vars->a->nbr < vars->a->next->nbr && vars->a->prev->nbr < vars->a->next->nbr) //132
	{
		rra(vars);
		sa(vars);
	}
}

void	solve(s_vars *vars)
{
	if (stack_size(vars->a) == 2)
		solve_for_2(vars);
	else if (stack_size(vars->a) == 3)
		solve_for_3(vars);
	else
	{
		
	}
	print_ops(vars->ops);
}
