/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:49 by rmocsai           #+#    #+#             */
/*   Updated: 2023/01/26 12:38:44 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				free_n_quit(NULL, "Error\n");
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
