/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:44:03 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:44 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	int	value;
	int	index;

	value = stack->value;
	index = stack->index;
	while (stack)
	{
		if (value < stack->value)
		{
			value = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int	get_min_index(t_stack *stack)
{
	int	value;
	int	index;

	value = stack->value;
	index = stack->index;
	while (stack)
	{
		if (value > stack->value)
		{
			value = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	max_index;
	int	min_index;

	max_index = get_max_index(*stack);
	min_index = get_min_index(*stack);
	if (max_index == 2 && min_index == 1)
		swap(stack, 'a');
	else if (max_index == 0 && min_index == 1)
		rotate(stack, 'a');
	else if (max_index == 1 && min_index == 2)
		reverse_rotate(stack, 'a');
	else if (max_index == 1 && min_index == 0)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (max_index == 0 && min_index == 2)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}
