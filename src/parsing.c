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

int	check_args2(int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	if (ac != 2)
		return (1);
	split = ft_split(av[1], ' ');
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[++j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]) && i != j)
				return (0);
		}
		j = -1;
		while (split[i][++j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != '-')
				return (0);
		}
	}
	return (1);
}

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
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != ' ')
				return (0);
		}
	}
	return (1);
}

t_stack	*parse_list_1(int ac, char **av)
{
	int		i;
	t_stack	*ret;
	t_stack	*current;

	i = 0;
	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (ret);
	current = ret;
	while (++i < ac)
	{
		current->nbr = ft_atoi(av[i]);
		current->index = i - 1;
		if (i < ac - 1)
		{
			current->next = (t_stack *)malloc(sizeof(t_stack));
			if (!current->next)
				return (NULL);
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (ret);
}

t_stack	*parse_list_2(char **av)
{
	int		i;
	t_stack	*ret;
	t_stack	*current;

	i = -1;
	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	current = ret;
	while (av[++i])
	{
		current->nbr = ft_atoi(av[i]);
		current->index = i;
		if (av[i + 1])
		{
			current->next = (t_stack *)malloc(sizeof(t_stack));
			if (!current->next)
				return (free_stack(ret), free_strs(av), NULL);
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (free_strs(av), ret);
}

t_stack	*parse_args(int ac, char **av)
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
