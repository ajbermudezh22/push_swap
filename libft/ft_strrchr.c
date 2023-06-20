/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:07:33 by albermud          #+#    #+#             */
/*   Updated: 2023/05/03 21:09:43 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*cptr;

	cptr = (void *)0;
	while (*s)
	{
		if (*s == (char)c)
			cptr = (char *)s;
		++s;
	}
	if (!(char)c)
		cptr = (char *)s;
	return (cptr);
}
