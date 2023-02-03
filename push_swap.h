/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:51 by rmocsai           #+#    #+#             */
/*   Updated: 2023/02/02 17:22:38 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./src/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
}			t_stacks;

//main
int		main(int ac, char **av);
void	validity_check(int ac, char **av);
void	free_n_quit(t_stacks *s, char *error);
void	check_double_or_done(t_stacks *s);
int		stack_sorted(t_stacks *s);

//inputparsing
void	parsing_input(int ac, char **av, t_stacks *s);
int		count_nbrs(char const *s, char c);
int		ft_newatoi(const char *str);

//utils
void	init_stacks(int ac, char **av, t_stacks *s);
void	indexing(t_stacks *s, long int *new_arr);

//sorting
void	sort_three(t_stacks *s);
void	sort_four(t_stacks *s);
void	sort_five(t_stacks *s);
void	radix_sort();
void	radix_helper();

//rulez
void	swap(int *arr, int size, char *str);
void	push(t_stacks *s, char *str);
void	rotate(int *arr, int size, char *direction, char *str);

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

#endif
