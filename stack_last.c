/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:38:35 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:47 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_second_last(t_stack *stack)
{
	t_stack	*scnd_last;

	scnd_last = stack;
	while (scnd_last && scnd_last->next->next)
		scnd_last = scnd_last->next;
	return (scnd_last);
}

t_stack	*stack_get_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}
