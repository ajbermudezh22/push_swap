/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:23:27 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:05 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ratio(int length)
{
	if (length < 10)
	{
		return (1);
	}
	else if (length < 100)
	{
		return ((length - 10) * 0.04 + 1);
	}
	else if (length < 500)
	{
		return ((length - 100) * 0.02 + 14);
	}
	else
	{
		return ((length - 500) * 0.006 + 30);
	}
}
