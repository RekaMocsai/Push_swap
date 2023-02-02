/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:20:56 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/02 17:00:30 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *arr, int size, char *str)
{
	int	x;

	if (size <= 0)
		return ;
	x = arr[0];
	arr[0] = arr[1];
	arr[1] = x;
	ft_putendl_fd(str, 1);
}

void	push(t_stacks *s, char *str)
{
	int	temp;		

	if (ft_strncmp(str, "pa", 4) == 0)
	{
		if (s->b_size <= 0)
			return ;
		temp = s->b[0];
		ft_memmove((s->a + 1), s->a, sizeof(int) * s->a_size);
		s->a[0] = temp;
		s->b_size--;
		ft_memmove(s->b, (s->b + 1), sizeof(int) * s->b_size);
		s->a_size++;
	}
	else if (ft_strncmp(str, "pb", 4) == 0)
	{
		if (s->a_size <= 0)
			return ;
		temp = s->a[0];
		ft_memmove((s->b + 1), s->b, sizeof(int) * s->b_size);
		s->b[0] = temp;
		s->a_size--;
		ft_memmove(s->a, (s->a + 1), sizeof(int) * s->a_size);
		s->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *arr, int size, char *direction, char *str)
{
	int	temp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		temp = arr[0];
		ft_memmove(arr, (arr + 1), sizeof(int) * (size - 1));
		arr[size - 1] = temp;
		ft_printf("%s", "r");
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		temp = arr[size - 1];
		ft_memmove((arr + 1), arr, sizeof(int) * (size - 1));
		arr[0] = tmp;
		ft_printf("%s", "rr");
	}
	ft_putendl_fd(str, 1);
}
