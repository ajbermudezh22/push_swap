/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:47:32 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:41 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **a, int length)
{
	t_stack		*b;

	b = NULL;
	fill_b(a, &b, length);
	sort_three(a);
	return_to_a(a, &b);
	clear_stack(&b);
}
