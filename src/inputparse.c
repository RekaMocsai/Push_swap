/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:57 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/14 12:35:48 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0)
		{
			if (str[i] == '\0' || \
			(!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'))
				return (0);
			if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
				return (0);
		}
		else
		{
			if (!ft_isdigit(str[i]))
				return (0);
		}
	}
	return (1);
}

int	ft_all_number(char **args, int size)
{
	while (size--)
	{
		if (!ft_isnumber(args[size]))
			return (0);
	}
	return (1);
}

int	split_helper(int ac, char **av, int count, char **all_args)
{
	char	**split_arg;
	int		i;
	int		offset;
	int		count_inter;

	i = 0;
	offset = 0;
	count_inter = 0;
	while (i++ < ac - 1)
	{
		count_inter = count_nbrs(av[i], ' ');
		split_arg = ft_split(av[i], ' ');
		if (!split_arg)
		{	
			while (count-- > 0)
				if (all_args[count])
					free(all_args[count]);
			free(all_args);
			return (0);
		}
		ft_memmove(all_args + offset, split_arg, count_inter * sizeof(char *));
		offset += count_inter;
		free(split_arg);
	}
	return (1);
}

int	split_args(int ac, char **av, t_sized_arr *arr)
{
	int		i;
	int		count;
	char	**all_args;

	i = 0;
	count = 0;
	while (i++ < ac - 1)
	{	
		if (count_nbrs(av[i], ' ') == 0)
			return (0);
		count += count_nbrs(av[i], ' ');
	}	
	all_args = ft_calloc(count, sizeof(char *));
	arr->size = count;
	arr->arr = all_args;
	if (!all_args)
		return (0);
	if (!split_helper(ac, av, count, all_args))
		return (0);
	return (1);
}

int	parse_integers(int ac, char **av, t_sized_arr *clean)
{
	int		i;
	char	**parsed_chars;
	int		*parsed_ints;

	clean->is_string_array = 1;
	if (!split_args(ac, av, clean) || !ft_all_number(clean->arr, clean->size))
		return (0);
	parsed_chars = clean->arr;
	parsed_ints = ft_calloc(clean->size, sizeof(int));
	i = -1;
	while (++i < clean->size)
	{
		if (ft_atol(parsed_chars[i]) > MAXI || ft_atol(parsed_chars[i]) < MINI)
		{
			free(parsed_ints);
			return (0);
		}
		parsed_ints[i] = ft_atol(parsed_chars[i]);
	}
	while (i--)
		free(parsed_chars[i]);
	free(parsed_chars);
	clean->arr = parsed_ints;
	clean->is_string_array = 0;
	return (1);
}
