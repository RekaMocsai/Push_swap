/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:49 by rmocsai           #+#    #+#             */
/*   Updated: 2023/01/30 13:50:41 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	if_double_or_done_then_quit(t_stacks *s, int i)
{
	int	j;

	if (i == 0)
	{
		while (i < s->a_size)
		{
			if (s->a[i] == s->a[j])
				free_n_quit(s, "Error, duplicate found\n");
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

	i = 0;
	while (i++ < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])) && (av[i][j] != ' ') && \
			(av[i][j] != '-' && av[i][j] != '+'))
				free_n_quit(NULL, "Error, input invalid\n");
			j++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	long int	*new_a;

	validity_check(ac, av);
	
	return (0);
}
