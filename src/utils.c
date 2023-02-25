/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:20:29 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/24 12:27:22 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(int ac, char **av, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (ac-- > 1)
	{
		s->a_size += count_nbrs(av[i + 1], ' ');
		i++;
	}
	s->a = ft_calloc(s->a_size, sizeof(int));
	if (!s->a)
		free_n_quit(s, "Error initializing\n");
	s->b = ft_calloc(s->a_size, sizeof(int));
	if (!s->b)
		free_n_quit(s, "Error initializing\n");
}

void	indexing(t_stacks *s, int *new_arr)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < s->a_size)
		new_arr[i] = s->a[i];
	bubblesort(new_arr, s->a_size);
	i = -1;
	while (++i < s->a_size)
	{
		j = -1;
		while (++j < s->a_size)
		{
			if (s->a[i] == new_arr[j])
			{
				s->a[i] = j;
				j = s->a_size + 1;
			}
		}
	}
	free(new_arr);
}

void	bubblesort(int *new_arr, int size)
{
	int	sort;
	int	i;
	int	swap;

	sort = 0;
	while (sort != 1)
	{
		sort = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (new_arr[i] > new_arr[i + 1])
			{
				swap = new_arr[i];
				new_arr[i] = new_arr[i + 1];
				new_arr[i + 1] = swap;
				sort = 0;
			}
			i++;
		}
	}
}
