/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:58:51 by albermud          #+#    #+#             */
/*   Updated: 2023/05/19 12:20:30 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static int	get_str_size(int value, int base)
{
	int	size;

	size = 0;
	if (value < 0 && base == 10)
		size++;
	while (value)
	{
		value /= base;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;

	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	flag = 0;
	if (value < 0 && base == 10)
		flag = 1;
	size = get_str_size(value, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (--size >= flag)
	{
		str[size] = tab[ft_abs(value % base)];
		value /= base;
	}
	return (str);
}
