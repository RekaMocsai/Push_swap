/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:57 by rmocsai           #+#    #+#             */
/*   Updated: 2023/01/27 13:38:43 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	parse_arr(t_stack *stack, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isinteger(av[i], false))
			terminate(ERROR_MESSAGE); // errors
		add(stack, create_elem(ft_atoi(av[i++])));
	}
}

static void	parse_str(t_stack *stack, char *str)
{
	char	**numbers;
	size_t	i;

	numbers = ft_split(str, ' ');
	i = 0;
	while (numbers[i])
	{
		if (!ft_isinteger(numbers[i], false))
			terminate(ERROR_MESSAGE);
		add(stack, create_elem(ft_atoi(numbers[i++])));
	}
	ft_split_free(&numbers);
}

t_stack		*parse(int ac, char **av)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	if (ac == 2 && !ft_isnum(av[1], 10))
		parse_str(stack, av[1]);
	else
		parse_arr(stack, ac, av);
	if (!stack->size)
		terminate(ERR_NO_NUMBERS);
	return (stack);
}


