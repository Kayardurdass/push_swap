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

t_stack	*get_last(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	get_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*current;

	current = stack;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	update_stack_indices(t_stack *stack)
{
	int		i;
	t_stack	*current;

	current = stack;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	update_indices(t_vars *vars)
{
	update_stack_indices(vars->a);
	update_stack_indices(vars->b);
}

t_stack	*get_at_index(int index, t_stack *stack)
{
	int		i;
	t_stack	*current;

	current = stack;
	i = -1;
	while (++i < index && current)
	{
		current = current->next;
	}
	return (current);
}
