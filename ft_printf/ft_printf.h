/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:51:25 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/06 15:21:11 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

int			ft_printf(const char *n, ...);
size_t		ft_strlen(const char *s);
int			print_pointer(int *i, va_list args);
int			print_unsigned(int *i, va_list args);
int			numlen_base(unsigned long n, int base);
int			print_str_chr(const char *format, int *i, va_list args);
int			print_int_sign(const char *format, int *i, va_list args);
int			handle_specifiers(const char *specifier, int *i, va_list args);
int			print_hex_upper_lower(const char *format, int *i, va_list args);
char		*itoa_base(unsigned long n, char *base);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		putnbr_unsigned_fd(unsigned int n, int fd);
#endif