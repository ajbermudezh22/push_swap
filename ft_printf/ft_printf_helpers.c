/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:40:08 by albermud          #+#    #+#             */
/*   Updated: 2023/05/19 19:32:44 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	write_char_and_count(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	write_str_and_count(char *s)
{
	size_t	count;

	if (s == NULL)
	{
		write(1, NULL_DISPLAY, ft_strlen(NULL_DISPLAY));
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

size_t	write_nbr_base_count(int nbr, char *base)
{
	int		base_length;
	long	long_nbr;
	size_t	count;

	base_length = ft_strlen(base);
	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		count += write_char_and_count('-');
		long_nbr *= -1;
	}
	if (long_nbr >= base_length)
		count += write_nbr_base_count(long_nbr / base_length, base);
	count += write_char_and_count(base[long_nbr % base_length]);
	return (count);
}

size_t	write_unbr_base_count(unsigned int nbr, char *base)
{
	unsigned long long	lnbr;
	unsigned int		base_length;
	size_t				count;

	lnbr = nbr;
	base_length = ft_strlen(base);
	count = 0;
	if (lnbr >= base_length)
		count += write_nbr_base_count(lnbr / base_length, base);
	count += write_char_and_count(base[lnbr % base_length]);
	return (count);
}

size_t	write_ptr_base_count(void *ptr, char *base, int first_loop_flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				count;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	count = 0;
	if (ptr == NULL)
	{
		count += write_str_and_count(NIL_DISPLAY);
		return (count);
	}
	if (first_loop_flag == 1)
		count += write_str_and_count(POINTER_PREFIX);
	if (nbr >= base_length)
		count += write_ptr_base_count((void *)(nbr / base_length), base, 0);
	count += write_char_and_count(base[nbr % base_length]);
	return (count);
}
