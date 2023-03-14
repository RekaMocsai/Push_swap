/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:20:29 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/14 10:45:13 by rmocsai          ###   ########.fr       */
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
		return (0);
	ft_memmove(s->a, arr, count * sizeof(int));
	return (1);
}

void	init_structs(t_stacks *s, t_sized_arr *a)
{
	s->a = NULL;
	s->b = NULL;
	a->arr = NULL;
}

int	indexing(t_stacks *s)
{
	int	i;
	int	j;
	int	*sorted;

	sorted = ft_calloc(s->a_size, sizeof(int));
	if (!sorted)
		return (0);
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
				break ;
			}
		}
	}
	free(sorted);
	return (1);
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

long	ft_atol(const char *str)
{
	int		i;
	int		pol;
	long	nbr;

	nbr = 0;
	pol = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pol = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * pol);
}
