#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	parse_arr(t_stack *stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i], false))
			terminate(ERROR_MESSAGE); // errors
		add(stack, create_elem(ft_atoi(argv[i++])));
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

t_stack		*parse(int argc, char **argv)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	if (argc == 2 && !ft_isnum(argv[1], 10))
		parse_str(stack, argv[1]);
	else
		parse_arr(stack, argc, argv);
	if (!stack->size)
		terminate(ERR_NO_NUMBERS);
	return (stack);
}
