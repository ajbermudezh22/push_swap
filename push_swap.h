/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:43:51 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 21:34:45 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_sort_params {
	int		value;
	int		index;
	t_bool	rotate;
}	t_sort_params;

// check_input.c
t_bool	is_valid_input(int n, char *argv[]);

// commands.c
void	push(t_stack **src, t_stack **dest, char x);
void	swap(t_stack **stack, char x);
void	rotate(t_stack **stack, char x);
void	reverse_rotate(t_stack **stack, char x);

// fill_b.c
void	fill_b(t_stack **a, t_stack **b, int length);

// is_sorted.c
t_bool	is_sorted(t_stack *stack);

// main.c
int		main(int argc, char *argv[]);

// map.c
int		map_number(int length, char *argv[], int i);

// print_cmd.c
void	print_cmd(char *str);

// ratio.c
int		get_ratio(int length);

// return_to_a.c
void	return_to_a(t_stack **a, t_stack **b);

// sort_big.c
void	sort_big(t_stack **a, int length);

// sort_three.c
void	sort_three(t_stack **stack);

// stack_last.c
t_stack	*stack_get_last(t_stack *stack);
t_stack	*stack_get_second_last(t_stack *stack);

// stack_operations.c
void	stack_update_index(t_stack **stack);
void	clear_stack(t_stack **stack);
t_stack	*init_stack(int length, char *argv[]);

// stack_utils.c
int		get_stack_length(t_stack *stack);
int		get_stack_middle(t_stack *stack);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_third_max_value(t_stack *stack);

#endif
