/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:39 by username          #+#    #+#             */
/*   Updated: 2025/01/22 03:42:16 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	update_stack_indices(s_stack *stack)
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

void	update_indices(s_vars *vars)
{
	update_stack_indices(vars->a);
	update_stack_indices(vars->b);
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
