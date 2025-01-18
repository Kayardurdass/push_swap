/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:39 by username          #+#    #+#             */
/*   Updated: 2025/01/18 18:29:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack	*get_last(s_stack *stack)
{
	s_stack	*current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	get_stack_size(s_stack *stack)
{
	int		i;
	s_stack	*current;
	
	current = stack;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	update_indices(s_stack *stack)
{
	int		i;
	s_stack	*current;

	current = stack;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

s_stack	*get_at_index(int index, s_stack *stack)
{
	int		i;
	s_stack	*current;
	
	current = stack;
	i = -1;
	while (++i < index && current)
	{
		current = current->next;
	}
	return (current);
}

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
