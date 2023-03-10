/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:49 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/10 17:25:34 by reka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pathfinder(t_stacks *s)
{
	if (stack_sorted(s))
		return;	
	else if (s->a_size == 2 && s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
	else if (s->a_size == 3)
		sort_three(s, 0);
	else if (s->a_size == 4)
		sort_four(s);
	else if (s->a_size == 5)
		sort_five(s);
	else
		radix_sort(s);
	if (!stack_sorted(s))
		ft_printf("Error");
}

int	check_duplicates(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void	free_n_quit(t_stacks *s, t_sized_arr *sized_arr, char *error)
{
	char **arr;
	
	if (error)
		ft_printf("%s\n", error);

	if (s->a != NULL)
		free (s->a);
	if (s->b != NULL)
		free (s->b);

	if (sized_arr->arr != NULL)
	{
		if (sized_arr->is_string_array)
		{
			arr = sized_arr->arr;
			while (sized_arr->size--)
			{
				free(arr[sized_arr->size]);
			}
		}
		free(sized_arr->arr);
	}
	exit(1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;	
	while (str[++i])
	{
		if (i == 0)
		{
			if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
				return (0) ;
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

int	ft_is_all_number(char **args, int size)
{
	while (size--)
	{
		if (!ft_isnumber(args[size]))
			return (0);
	}

	return (1);
}

int	split_args(int ac, char **av,t_sized_arr *arr)
{
	int		offset;
	int		i;
	int 	count;
	int		count_internal;
	char	**split_arg;
	char	**all_args;
	
	i = 0;
	count = 0;
	while (i++ < ac - 1)
	{
		count += count_nbrs(av[i], ' ');
	}	
	all_args = ft_calloc(count, sizeof(char *));
	arr->size = count;
	arr->arr = all_args;
	
	if (!all_args)
		return (0);
	
	i = 0;
	offset = 0;
	while (i++ < ac - 1)
	{
		count_internal = count_nbrs(av[i], ' ');
		split_arg = ft_split(av[i], ' ');
		if (!split_arg)
		{	
			while (count-- > 0)
				if (all_args[count])
					free(all_args[count]);
			free(all_args);
			return (0);
		}
		ft_memmove(all_args + offset, split_arg, count_internal * sizeof(char *));
		offset += count_internal;
		free(split_arg);
	}
	return (1);
}

int	parse_integers(int ac, char **av,t_sized_arr *parsed_args)
{
	int		i;
	char	**parsed_chars;
	int		*parsed_ints;
	
	parsed_args->is_string_array = 1;
	if (!split_args(ac, av, parsed_args) || 
		!ft_is_all_number(parsed_args->arr, parsed_args->size))
		return 0;
	parsed_chars = parsed_args->arr;
	parsed_ints = ft_calloc(parsed_args->size, sizeof(int));
	i = -1;
	while (++i < parsed_args->size)	
	{
		if (ft_newatoi(parsed_chars[i]) > MAX_I || ft_newatoi(parsed_chars[i]) < MIN_I)
		{
			free(parsed_ints);
			return 0;
		}
		parsed_ints[i] = ft_newatoi(parsed_chars[i]);
	}
	while (i--)
		free(parsed_chars[i]);
	free(parsed_chars);
	parsed_args->arr = parsed_ints;
	parsed_args->is_string_array = 0;
	return 1;
}


void init_structs(t_stacks *s, t_sized_arr *a)
{
	s->a = NULL;
	s->b = NULL;
	a->arr = NULL;
	
}

int	main(int ac, char **av)
{	
	t_stacks	s;
	t_sized_arr	parsed_args;
	
	init_structs(&s, &parsed_args);
	if (!parse_integers(ac, av, &parsed_args))
		free_n_quit(&s,&parsed_args, "Error");
	if (!check_duplicates(parsed_args.arr, parsed_args.size))
		free_n_quit(&s,&parsed_args, "Error");
	if (!init_stacks(parsed_args.arr, parsed_args.size, &s))
		free_n_quit(&s,&parsed_args, "Error");
	if (!indexing(&s))
		free_n_quit(&s,&parsed_args, "Error");
	
	pathfinder(&s);
	free_n_quit(&s,&parsed_args, NULL);
	return (0);
}