/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:22:21 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/17 01:21:52 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	free_stack(s_stack *stack)
{
	s_stack	*current;

	current = stack;
	while (current->next != stack)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
}


s_stack	*get_big(s_stack *stack)
{
	long	most;
	s_stack	*ret;
	s_stack	*current;

	current = stack;
	most = LONG_MIN;
	while (current->next != stack)
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

s_op_lst	*get_last_op(s_op_lst *ops)
{
	s_op_lst	*current;

	current = ops;
	while (current->next_op != NULL)
		current = current->next_op;
	return (current);
}

void	ad_op(e_op op, s_op_lst *ops)
{
	if (ops->op == NO_OP)
	{
		ops->op = op;
		return ;
	}
	get_last_op(ops)->next_op = (s_op_lst*)malloc(sizeof(s_op_lst));
	get_last_op(ops)->next_op = NULL;
	get_last_op(ops)->op = op;
}

void	print_ops(s_op_lst *ops)
{
	s_op_lst	*current;

	current = ops;
	while (current != NULL)
	{
		if (current->op == SA)
			printf("sa\n");
		if (current->op == SB)
			printf("sb\n");
		if (current->op == SS)
			printf("ss\n");
		if (current->op == PA)
			printf("pa\n");
		if (current->op == PB)
			printf("pb\n");
		if (current->op == RA)
			printf("ra\n");
		if (current->op == RB)
			printf("rb\n");
		if (current->op == RR)
			printf("rr\n");
		if (current->op == RRA)
			printf("rra\n");
		if (current->op == RRB)
			printf("rrb\n");
		if (current->op == RRR)
			printf("rrr\n");
		current = current->next_op;
	}
}

s_stack	*get_little(s_stack *stack)
{
	long	least;
	s_stack	*ret;
	s_stack	*current;

	current = stack;
	least = LONG_MAX;
	while (current->next != stack)
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

int	stack_size(s_stack *stack)
{
	s_stack	*current;
	int		i;

	i = 0;
	if (!stack)
		return (i);
	current = stack;
	while (current->next != stack)
	{
		current = current->next;
		i++;
	}
	return (i + 1);
}
