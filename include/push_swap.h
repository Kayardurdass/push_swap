/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:13:00 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 05:36:33 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}			t_stack;

typedef enum s_op
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
}			t_op;

typedef struct e_op_lst
{
	t_op			op;
	struct e_op_lst	*next_op;
}			t_op_lst;

typedef struct t_vars
{
	t_stack		*a;
	t_stack		*b;
	t_op_lst	*ops;
}	t_vars;

void		free_strs(char **strs);
void		free_stack(t_stack *stack);
int			check_args(int ac, char **av);
t_stack		*parse_args(int ac, char **av);
void		print_ops(t_op_lst *ops);
t_op_lst	*get_last_op(t_op_lst *ops);
t_stack		*get_last(t_stack *stack);
t_stack		*get_big(t_stack *stack);
t_stack		*get_little(t_stack *stack);
int			get_cost_to_top(t_stack *stack, t_stack *to_move);
t_stack		*get_best_place(t_stack *stack, t_stack *to_place, int order);
void		get_to_top(t_stack *stack, t_stack *to_move, \
			t_vars *vars, int wich_stack);
t_stack		*get_next_nb_to_push(t_vars *vars);
void		free_ops(t_op_lst *ops);
void		back_to_a(t_vars *vars);
void		pb(t_vars *vars);
void		pa(t_vars *vars);
void		sa(t_vars *vars);
void		sb(t_vars *vars);
void		ss(t_vars *vars);
void		ra(t_vars *vars);
void		rb(t_vars *vars);
void		rr(t_vars *vars);
void		rra(t_vars *vars);
void		rrb(t_vars *vars);
void		rrr(t_vars *vars);
int			get_stack_size(t_stack *stack);
void		free_stack(t_stack *stack);
void		solve(t_vars *vars);
void		ad_op(t_op op, t_op_lst *ops, t_vars *vars);
void		remove_op(t_op_lst *ops, t_op_lst *to_remove);
int			is_sorted(t_vars *vars);
t_stack		*get_at_index(int index, t_stack *stack);
void		update_indices(t_vars *vars);
void		do_op(int n, t_vars *vars, void (*f)(t_vars *vars));

#endif // !PUSH_SWAP_H
