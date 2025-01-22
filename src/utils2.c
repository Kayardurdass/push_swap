/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:24:03 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 05:37:48 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_ops(s_op_lst *ops)
{
	s_op_lst	*current;
	s_op_lst	*tmp;

	current = ops;
	while (current)
	{
		tmp = current;
		current = current->next_op;
		free(tmp);
	}
}
