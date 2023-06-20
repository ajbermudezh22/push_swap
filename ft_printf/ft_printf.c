/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:27:36 by albermud          #+#    #+#             */
/*   Updated: 2023/05/19 19:31:53 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	process_data(char specifier, va_list ap)
{
	size_t	char_count;

	char_count = 0;
	if (specifier == 'c')
		char_count = write_char_and_count(va_arg(ap, int));
	else if (specifier == 's')
		char_count = write_str_and_count(va_arg(ap, char *));
	else if (specifier == 'p')
		char_count = write_ptr_base_count(va_arg(ap, void *), HEX_BASE_LOW, 1);
	else if (specifier == 'd' || specifier == 'i')
		char_count = write_nbr_base_count(va_arg(ap, int), DEC_BASE);
	else if (specifier == 'u')
		char_count = write_unbr_base_count(va_arg(ap, unsigned int), DEC_BASE);
	else if (specifier == 'x')
		char_count = write_unbr_base_count(va_arg(ap, unsigned int),
				HEX_BASE_LOW);
	else if (specifier == 'X')
		char_count = write_unbr_base_count(va_arg(ap, unsigned int),
				HEX_BASE_UP);
	else if (specifier == '%')
		char_count = write_char_and_count('%');
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	char_count;

	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			char_count += process_data(*++format, args);
			format++;
		}
		else
			char_count += write_char_and_count(*format++);
	}
	va_end(args);
	return (char_count);
}
