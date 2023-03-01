/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:57 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/01 16:12:57 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parsing_input(int ac, char **av, t_stacks *s)
{
	char	*str;
	char	**temp;
	int		j;
	int		i;

	str = strjoiner(ac, av, s);
	temp = ft_split(str, ' ');
	free(str);
	j = 0;
	i = 0;
	while (temp[j])
	{
		if (ft_newatoi(temp[j]) > MAX_I || ft_newatoi(temp[j]) < MIN_I)
		{
			j = 0;
			while (temp[j])
				free(temp[j++]);
			free(temp);
			free_n_quit(s, "Error");
		}
		s->a[i++] = (int)ft_newatoi(temp[j++]);
	}
	justfree(temp);
}

void	justfree(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
}

char	*strjoiner(int ac, char **av, t_stacks *s)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = ft_calloc(1, 1);
	i = 1;
	while (ac-- > 1)
	{
		if (av[i][0] == '\0' )
		{
			free(str1);
			free_n_quit(s, "Error");
		}
		str2 = ft_strjoin(str1, " ");
		free(str1);
		str1 = ft_strjoin(str2, av[i++]);
		free(str2);
	}
	return (str1);
}

long	ft_newatoi(const char *str)
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
