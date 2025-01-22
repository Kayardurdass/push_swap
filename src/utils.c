/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:41:09 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 03:59:27 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	remove_op(s_op_lst *ops, s_op_lst *to_remove)
{
	s_op_lst	*current;
	s_op_lst	*tmp;

	if (!ops || !to_remove)
		return ;
	if (ops->next_op == NULL)
	{
		ops->op = NO_OP;
		return ;
	}
	current = ops;
	while (current->next_op != to_remove && current != NULL)
		current = current->next_op;
	tmp = current->next_op;
	current->next_op = current->next_op->next_op;
	free(tmp);
}

s_op_lst	*get_last_op(s_op_lst *ops)
{
	s_op_lst	*current;

	if (!ops)
		return (ops);
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
		ops->next_op = NULL;
		return ;
	}
	get_last_op(ops)->next_op = (s_op_lst *)malloc(sizeof(s_op_lst));
	get_last_op(ops)->next_op = NULL;
	get_last_op(ops)->op = op;
}

void	print_ops2(e_op op)
{
	if (op == SA)
		printf("sa\n");
	if (op == SB)
		printf("sb\n");
	if (op == SS)
		printf("ss\n");
	if (op == PA)
		printf("pa\n");
	if (op == PB)
		printf("pb\n");
	if (op == RA)
		printf("ra\n");
	if (op == RB)
		printf("rb\n");
	if (op == RR)
		printf("rr\n");
	if (op == RRA)
		printf("rra\n");
	if (op == RRB)
		printf("rrb\n");
	if (op == RRR)
		printf("rrr\n");
}

void	print_ops(s_op_lst *ops)
{
	s_op_lst	*current;

	current = ops;
	while (current != NULL)
	{
		print_ops2(current->op);
		current = current->next_op;
	}
}
