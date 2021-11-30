/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:01:46 by jthor             #+#    #+#             */
/*   Updated: 2021/11/10 18:04:43 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	conversion_handle(int ret_total, char c, va_list ap);

int	print_char(int ret_total, char c);
int	print_string(int ret_total, char *str);

int	handle_decimal(int ret_total, int x);
int	handle_unsigned(int ret_total, unsigned int n);
int	handle_hex(char c, int ret_total, unsigned int n);
int	handle_ptr(int ret_total, unsigned long n);

#endif
