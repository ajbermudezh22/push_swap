/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:39:41 by albermud          #+#    #+#             */
/*   Updated: 2023/05/05 17:20:18 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	memsize;
	size_t	i;
	char	*sub;

	memsize = 1;
	i = 0;
	if (s)
	{
		while (s[i] && i < start)
			++i;
		while (s[i++] && len--)
			++memsize;
	}
	sub = malloc (memsize);
	if (!sub)
		return (NULL);
	sub[--memsize] = 0;
	while (memsize--)
		sub[memsize] = s[start + memsize];
	return (sub);
}
