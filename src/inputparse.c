/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:57 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/14 17:22:19 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parsing_input(int ac, char **av, t_stacks *s)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	while (ac-- > 1)
	{
		if (av[j + 1][0] == '\0')
			free_n_quit(s, "Error");
		if (count_nbrs(av[j + 1], ' ') == 1)
			s->a[j] = ft_newatoi(av[j + 1]);
		else if (count_nbrs(av[j + 1], ' ') > 1)
		{
			temp = ft_split(av[j + 1], ' ');
			i = 0;
			while (temp[i])
				s->a[j++] = ft_newatoi(temp[i++]);
			i = 0;
			while (temp[i])
				free(temp[i++]);
			free(temp);
			j--;
		}
		j++;
	}
}

int	count_nbrs(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	ft_newatoi(const char *str)
{
	int			i;
	long		pol;
	long long	nbr;

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
	if (!ft_isdigit(str[0]) && str[i] != ' ' && str[i] != 0)
		free_n_quit(NULL, "Error, invalid input");
	if ((nbr * pol) < MIN_INT || (nbr * pol) > MAX_INT)
		free_n_quit(NULL, "Error, invalid input");
	return ((int)(nbr * pol));
}