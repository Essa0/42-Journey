/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:51:25 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/08 00:39:19 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft/libft.h"

int			ft_printf(const char *n, ...);
int			print_pointer(int *i, va_list args);
int			print_unsigned(int *i, va_list args);
int			numlen_base(unsigned long n, int base);
int			print_str_chr(const char *format, int *i, va_list args);
int			print_int_sign(const char *format, int *i, va_list args);
int			handle_specifiers(const char *specifier, int *i, va_list args);
int			print_hex_upper_lower(const char *format, int *i, va_list args);
char		*itoa_base(unsigned long n, char *base);
void		putnbr_unsigned_fd(unsigned int n, int fd);
#endif