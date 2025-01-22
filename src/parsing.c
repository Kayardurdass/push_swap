/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uanglade <uanglade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:27:02 by uanglade          #+#    #+#             */
/*   Updated: 2025/01/22 03:29:29 by uanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

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

s_stack	*parse_list_1(int ac, char **av)
{
	int		i;
	s_stack	*ret;
	s_stack	*current;

	i = 0;
	ret = (s_stack *)malloc(sizeof(s_stack));
	if (!ret)
		return (ret);
	current = ret;
	while (++i < ac)
	{
		current->nbr = ft_atoi(av[i]);
		current->index = i - 1;
		if (i < ac - 1)
		{
			current->next = (s_stack *)malloc(sizeof(s_stack));
			if (!current->next)
				return (NULL);
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (ret);
}

s_stack	*parse_list_2(char **av)
{
	int		i;
	s_stack	*ret;
	s_stack	*current;

	i = -1;
	ret = (s_stack *)malloc(sizeof(s_stack));
	if (!ret)
		return (NULL);
	current = ret;
	while (av[++i])
	{
		current->nbr = ft_atoi(av[i]);
		current->index = i;
		if (av[i + 1])
		{
			current->next = (s_stack *)malloc(sizeof(s_stack));
			if (!current->next)
				return (free_stack(ret), free_strs(av), NULL);
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (free_strs(av), ret);
}

s_stack	*parse_args(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			return (NULL);
		return (parse_list_2(av));
	}
	else
		return (parse_list_1(ac, av));
}
