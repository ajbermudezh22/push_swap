/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:45:50 by albermud          #+#    #+#             */
/*   Updated: 2023/05/05 17:20:33 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	ret[i] = 0;
	return (ret);
}
/*
#include <stdio.h>

char my_function(unsigned int index, char c)
{
    if (index % 2 == 0)
        return (c + 1);
    else
        return (c - 1);
}

int main(void)
{
    char *s = "abcdefg";
    char *result = ft_strmapi(s, &my_function);
    printf("Original string: %s\n", s);
    printf("Modified string: %s\n", result);
    free(result);
    return (0);
}
*/