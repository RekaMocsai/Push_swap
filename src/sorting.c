/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:49:08 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/09 11:11:18 by reka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stacks *s, int x)
{
	if (s->a[2] != x + 2)
	{
		if (s->a[0] == x + 2)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
}

void	sort_four(t_stacks *s)
{
	while (s->b_size < 1)
	{
		if (s->a[0] == 0)
			push(s, "pb");
		else if (s->a[3] == 0)
			rotate(s->a, s->a_size, "down", "a");
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	sort_three(s, 1);
	push(s, "pa");
}

void	sort_five(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push(s, "pb");
		else if (s->a[4] == 0)
			rotate(s->a, s->a_size, "down", "a");
		else if (s->a[3] == 0)
		{
			rotate(s->a, s->a_size, "down", "a");
			rotate(s->a, s->a_size, "down", "a");
		}
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0)
		swap(s->b, s->b_size, "sb");
	sort_three(s, 2);
	push(s, "pa");
	push(s, "pa");
}

void	radix_sort(t_stacks *s)

{
	int	i;
	int	bit_count;
	int	size;

	i = -1;
	bit_count = 0;
	size = s->a_size;
	while (++bit_count && size > 1)
		size /= 2;
	while (++i < bit_count)
	{
		size = s->a_size;
		while (size--)
		{
			if (((s->a[0] >> i) & 1))
				rotate(s->a, s->a_size, "up", "a");
			else
				push(s, "pb");
		}
		while (s->b_size != 0)
			push(s, "pa");
	}	
}

int	stack_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
