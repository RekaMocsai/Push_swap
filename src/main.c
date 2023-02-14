/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:49 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/14 17:22:13 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pathfinder(t_stacks *s)
{
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
	else if (s->a_size == 3)
		sort_three(s);
	else if (s->a_size == 4)
		sort_four(s);
	else if (s->a_size == 5)
		sort_five(s);
	else
		radix_sort(s);
	if (stack_sorted(s))
		free_n_quit(s, NULL);
}

void	check_double_or_done(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->a[i] == s->a[j])
				free_n_quit(s, "Error, duplicate found");
			j++;
		}
		i++;
	}
	if (stack_sorted(s))
		free_n_quit(s, NULL);
}

void	free_n_quit(t_stacks *s, char *error)
{
	if (error)
		ft_printf("%s\n", error);
	if (s != NULL)
	{
		if (s->a != NULL)
			free (s->a);
		if (s->b != NULL)
			free (s->b);
		if (s != NULL)
			free (s);
	}
	exit(1);
}

void	validity_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])) && (av[i][j] != ' ') && \
			(av[i][j] != '-' && av[i][j] != '+'))
				free_n_quit(NULL, "Error, input invalid");
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	long int	*new_arr;

	validity_check(ac, av);
	s = malloc(sizeof (*s));
	if (s == NULL)
		exit(1);
	init_stacks(ac, av, s);
	parsing_input(ac, av, s);
	check_double_or_done(s);
	new_arr = malloc(s->a_size * sizeof * new_arr);
	if (new_arr == NULL)
		free_n_quit(s, "Error");
	indexing(s, new_arr);
	pathfinder(s);
	free_n_quit(s, "Error last minute");
	return (0);
}
