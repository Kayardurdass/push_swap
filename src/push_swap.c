/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:19:17 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 05:40:54 by uanglade         ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

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

void	optimize_ops(t_vars *vars)
{
	t_op_lst	*current;
	t_op_lst	*tmp;

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
	t_vars	*vars;

	if (ac < 2 || !check_args(ac, av))
		return (write(1, "Error\n", 6));
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (-1);
	vars->a = parse_args(ac, av);
	if (!vars->a)
		return (free(vars), -1);
	vars->b = NULL;
	vars->ops = malloc(sizeof(t_op_lst));
	if (!vars->ops)
		return (free_stack(vars->a), free(vars), -1);
	vars->ops->op = NO_OP;
	solve(vars);
	optimize_ops(vars);
	print_ops(vars->ops);
	free_stack(vars->a);
	free_stack(vars->b);
	free(vars);
}
