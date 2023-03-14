/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:49 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/14 11:49:24 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pathfinder(t_stacks *s)
{
	if (stack_sorted(s))
		return ;
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_nbrs(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	free_n_quit(t_stacks *s, t_sized_arr *sized_arr, char *error)
{
	char	**arr;

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

int	main(int ac, char **av)
{	
	t_stacks	s;
	t_sized_arr	parsed_args;

	init_structs(&s, &parsed_args);
	if (!parse_integers(ac, av, &parsed_args))
		free_n_quit(&s, &parsed_args, "Error");
	if (!check_duplicates(parsed_args.arr, parsed_args.size))
		free_n_quit(&s, &parsed_args, "Error");
	if (!init_stacks(parsed_args.arr, parsed_args.size, &s))
		free_n_quit(&s, &parsed_args, "Error");
	if (!indexing(&s))
		free_n_quit(&s, &parsed_args, "Error");
	pathfinder(&s);
	free_n_quit(&s, &parsed_args, NULL);
	return (0);
}
