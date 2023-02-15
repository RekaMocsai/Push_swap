/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:49:08 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/15 15:32:05 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stacks *s)
{
	if (s->a[2] != 2)
	{
		if (s->a[0] == 2)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
}

void	sort_four(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push(s, "pb");
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
	push(s, "pa");
}

void	sort_five(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push(s, "pb");
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0)
		swap(s->b, s->b_size, "sb");
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap(s->a, s->a_size, "sa");
	push(s, "pa");
	push(s, "pa");
}

void	radix_sort_helper(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size)
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push(s, "pa");
	}
}

void	radix_sort(t_stacks *s)

{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !stack_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				push(s, "pb");
			else
				rotate(s->a, s->a_size, "up", "a");
		}
		radix_sort_helper(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		push(s, "pa");
}