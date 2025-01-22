/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:19:17 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 03:29:58 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	free_stack(s_stack *stack)
{
	s_stack	*current;
	s_stack	*tmp;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
}

void	print_stack(s_stack *stack)
{
	s_stack	*current;

	if (!stack)
	{
		printf("Stack empty\n");
		return ;
	}
	current = stack;
	while (current != NULL)
	{
		printf("index: %ld, value: %ld\n", current->index, current->nbr);
		current = current->next;
	}
}

void	optimize_ops(s_vars *vars)
{
	s_op_lst	*current;
	s_op_lst	*tmp;

	current = vars->ops;
	while (current)
	{
		if (current->next_op)
		{
			if (current->op == RA && current->next_op->op == RB)
			{
				tmp = current->next_op->next_op;
				free(current->next_op);
				current->op = RR;
				current->next_op = tmp;
			}
			if (current->op == RRA && current->next_op->op == RRB)
			{
				tmp = current->next_op->next_op;
				free(current->next_op);
				current->op = RRR;
				current->next_op = tmp;
			}
		}
		current = current->next_op;
	}
}

int	main(int ac, char **av)
{
	s_vars	*vars;

	if (ac < 2 || !check_args(ac, av))
		return (-1);
	vars = (s_vars *)malloc(sizeof(s_vars));
	vars->a = parse_args(ac, av);
	if (!vars->a)
		return (free(vars), -1);
	vars->b = NULL;
	vars->ops = malloc(sizeof(s_op_lst));
	vars->ops->op = NO_OP;
	solve(vars);
	optimize_ops(vars);
	print_ops(vars->ops);
}
