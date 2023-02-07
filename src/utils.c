/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:20:29 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/06 16:41:39 by rmocsai          ###   ########.fr       */
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
	s->a = malloc(s->a_size * sizeof(s->a));
	if (!s->a)
		free_n_quit(s, "Error initializing\n");
	s->b = malloc(s->a_size * sizeof(s->b));
	if (!s->b)
		free_n_quit(s, "Error initializing\n");
}

void	indexing(t_stacks *s, long int *new_arr)
{
	int		i;
	int		j;
	int		k;
	long	min;

	i = s->a_size;
	while (i--)
		new_arr[i] = s->a[i];
	i = 0;
	while (i < s->a_size)
	{
		j = 0;
		min = MIN_INT * -1;
		while (j < s->a_size)
		{
			if (new_arr[j++] < min)
			{
				min = new_arr[j - 1];
				k = j - 1;
			}
		}
		new_arr[k] = MIN_INT * -1;
		s->a[k] = i++;
	}
	free(new_arr);
}
/* GPT cerated bubble sort
void	create_index(t_stacks *s, long int *new_a)
{
	int			i;
	int			j;
	int			k;
	long int	min;
	int			flag;

	i = s->a_size;
	while (i--)
		new_a[i] = s->a[i];
	for (i = 0; i < s->a_size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < s->a_size - i - 1; j++)
		{
			if (new_a[j] > new_a[j + 1])
			{
				swap(&new_a[j], &new_a[j + 1], );
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (i = 0; i < s->a_size; i++)
	{
		k = 0;
		min = new_a[i];
		while (k < s->a_size && s->a[k] != min)
			k++;
		s->a[k] = i;
	}
	free(new_a);
}

void swap(long int *a, long int *b)
{
	long int temp = *a;
	*a = *b;
	*b = temp;
}*/
