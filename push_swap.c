/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:19:17 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/18 18:56:25 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int	check_args(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (++j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]) && i != j)
				return (0);
		}
	}
	return (1);
}

s_stack *parse_list(int ac, char **av)
{
	int		i;
	s_stack	*ret;
	s_stack	*current;

	i = 0;
	ret = (s_stack*)malloc(sizeof(s_stack));
	current = ret;
	while (++i < ac)
	{
		current->nbr = ft_atoi(av[i]);
		current->index = i - 1;
		if (i < ac - 1)
		{
			current->next = (s_stack*)malloc(sizeof(s_stack));
			current = current->next;
		}
		else
		{
			current->next = NULL;
		}
	}
	return (ret);
}

void print_stack(s_stack *stack)
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

int main(int ac, char **av)
{
	s_vars *vars;
	if (ac <= 2 || !check_args(ac, av))
		return (-1);
	vars = (s_vars*)malloc(sizeof(s_vars));
	vars->a = parse_list(ac, av);
	vars->b = NULL;
	vars->ops = malloc(sizeof(s_op_lst));
	vars->ops->op = NO_OP;
	/*printf("a: \nsize: %d\n", get_stack_size(vars->a));
	print_stack(vars->a);
	printf("b: \nsize: %d\n", get_stack_size(vars->b));
	print_stack(vars->b);*/
	solve(vars);
	print_ops(vars->ops);
	/*printf("a: \nsize: %d\n", get_stack_size(vars->a));
	print_stack(vars->a);
	printf("b: \nsize: %d\n", get_stack_size(vars->b));
	print_stack(vars->b);*/
}
