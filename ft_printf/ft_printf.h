/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:44:01 by albermud          #+#    #+#             */
/*   Updated: 2023/05/19 19:27:13 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC_BASE "0123456789"
# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"
# define POINTER_PREFIX "0x"
# define NULL_DISPLAY "(null)"
# define NIL_DISPLAY "(nil)"

int		ft_printf(const char *format, ...);
size_t	write_char_and_count(int c);
size_t	write_str_and_count(char *s);
size_t	write_nbr_base_count(int nbr, char *base);
size_t	write_unbr_base_count(unsigned int nbr, char *base);
size_t	write_ptr_base_count(void *ptr, char *base, int first_loop_flag);

#endif
