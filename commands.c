/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:43:57 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:15 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest, char x)
{
	t_stack	*temp;

	temp = (*src);
	(*src) = (*src)->next;
	temp->next = (*dest);
	(*dest) = temp;
	stack_update_index(src);
	stack_update_index(dest);
	if (x == 'a')
		print_cmd("pa");
	else
		print_cmd("pb");
}

void	swap(t_stack **stack, char x)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->index = 1;
	(*stack)->next = (*stack)->next->next;
	second->next = *stack;
	second->index = 0;
	(*stack) = second;
	if (x == 'a')
		print_cmd("sa");
	else
		print_cmd("sb");
}

void	rotate(t_stack **stack, char x)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = stack_get_last(*stack);
	last->next = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	stack_update_index(stack);
	if (x == 'a')
		print_cmd("ra");
	else
		print_cmd("rb");
}

void	reverse_rotate(t_stack **stack, char x)
{	
	t_stack	*last;
	t_stack	*scnd_last;
	t_stack	*temp;

	last = stack_get_last(*stack);
	scnd_last = stack_get_second_last(*stack);
	scnd_last->next = NULL;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	stack_update_index(stack);
	if (x == 'a')
		print_cmd("rra");
	else
		print_cmd("rrb");
}
