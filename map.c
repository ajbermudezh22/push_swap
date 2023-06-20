/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:59 by albermud          #+#    #+#             */
/*   Updated: 2023/06/09 20:27:29 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	map_number(int length, char *argv[], int i)
{
	int	smaller;
	int	j;

	j = 1;
	smaller = 0;
	while (j <= length)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[j]))
			smaller++;
		j++;
	}
	return (length - smaller);
}
