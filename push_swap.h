/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:51 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/10 16:21:54 by reka             ###   ########.fr       */
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

typedef struct s_sized_arr
{
	void	*arr;
	int		size;
	int 	is_string_array; 
}			t_sized_arr;

//main
int		main(int ac, char **av); 
int		ft_is_all_number(char **str, int size);
int		split_args(int ac, char **av, t_sized_arr *arr);
void	free_n_quit(t_stacks *s, t_sized_arr *sized_arr, char *error);
int		check_duplicates(int *arr, int count);
void	pathfinder(t_stacks *s);

//inputparsing

//int		parsing_input(int ac, char **av, t_stacks *s);
void	justfree(char **temp);
char	*strjoiner(int ac, char **av, t_stacks *s);
long	ft_newatoi(const char *str);

//utils
int		init_stacks(int *arr, int count, t_stacks *s);
int		count_nbrs(char const *s, char c);
int		indexing(t_stacks *s);
void	bubblesort(int *new_arr, int size);

//sorting
void	sort_three(t_stacks *s, int x);
void	sort_four(t_stacks *s);
void	sort_five(t_stacks *s);
void	radix_sort(t_stacks *s);
int	stack_sorted(t_stacks *s);

//rulez
void	swap(int *arr, int size, char *str);
void	push(t_stacks *s, char *str);
void	rotate(int *arr, int size, char *direction, char *str);

# ifndef MIN_I
#  define MIN_I -2147483648
# endif

# ifndef MAX_I
#  define MAX_I 2147483647
# endif

#endif
