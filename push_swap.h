/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:13:00 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/17 01:23:57 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"


typedef struct t_stack
{
	long	nbr;
	long	index;
	struct t_stack *prev;
	struct t_stack *next;
}			s_stack;

typedef enum t_op
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PB,
	PA,
	NO_OP,
}			e_op;

typedef struct t_op_lst
{
	e_op			op;
	struct t_op_lst	*next_op;
}			s_op_lst;

typedef struct t_vars
{
	s_stack		*a;
	s_stack		*b;
	s_op_lst	*ops;
}	s_vars;

void	print_ops(s_op_lst *ops);
s_op_lst	*get_last_op(s_op_lst *ops);
void	push_to_stack(s_stack **stack_a, s_stack **stack_b);
void	pb(s_vars *vars);
void	pa(s_vars *vars);
void	sa(s_vars *vars);
void	sb(s_vars *vars);
void	ss(s_vars *vars);
void	ra(s_vars *vars);
void	rb(s_vars *vars);
void	rr(s_vars *vars);
void	rra(s_vars *vars);
void	rrb(s_vars *vars);
void	rrr(s_vars *vars);
int		stack_size(s_stack *stack);
void	free_stack(s_stack *stack);
void	solve(s_vars *vars);
void	ad_op(e_op op, s_op_lst *ops);

#endif // !PUSH_SWAP_H
