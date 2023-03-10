/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:20:29 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/10 16:29:50 by reka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_stacks(int *arr, int count, t_stacks *s)
{
	s->a_size = count;
	s->b_size = 0;
	s->a = ft_calloc(s->a_size, sizeof(int));
	if (!s->a)
		return (0);
	s->b = ft_calloc(s->a_size, sizeof(int));
	if (!s->b)
		return(0);
	
	ft_memmove(s->a, arr, count * sizeof(int));
	
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

int		indexing(t_stacks *s)
{
	int	i;
	int	j;
	int *sorted;
	
	sorted = ft_calloc(s->a_size, sizeof(int));
	if (!sorted)
		return 0;
	ft_memmove(sorted, s->a, s->a_size * sizeof(int));
	bubblesort(sorted, s->a_size);
	i = -1;
	while (++i < s->a_size)
	{
		j = -1;
		while (++j < s->a_size)
		{
			if (s->a[i] == sorted[j])
			{
				s->a[i] = j;
				break;
			}
		}
	}
	free(sorted);
	return 1;
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
