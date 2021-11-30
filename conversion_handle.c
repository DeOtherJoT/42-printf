/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:59:09 by jthor             #+#    #+#             */
/*   Updated: 2021/11/26 15:00:34 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_handle(int ret_total, char c, va_list ap)
{
	if (c == 'c')
		ret_total = print_char(ret_total, va_arg(ap, int));
	else if (c == 's')
		ret_total = print_string(ret_total, va_arg(ap, char *));
	else if (c == 'p')
		ret_total = handle_ptr(ret_total, va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		ret_total = handle_decimal(ret_total, va_arg(ap, int));
	else if (c == 'u')
		ret_total = handle_unsigned(ret_total, va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		ret_total = handle_hex(c, ret_total, va_arg(ap, unsigned int));
	else if (c == '%')
		ret_total = print_char(ret_total, '%');
	return (ret_total);
}

int	print_char(int ret_total, char c)
{
	ret_total++;
	write(1, &c, 1);
	return (ret_total);
}

int	print_string(int ret_total, char *str)
{
	if (str == NULL)
	{
		ret_total = print_string(ret_total, "(null)");
		return (ret_total);
	}
	while (*str)
	{
		ret_total = print_char(ret_total, *str);
		str++;
	}
	return (ret_total);
}

int	handle_decimal(int ret_total, int x)
{
	char	*numb;

	numb = ft_itoa(x);
	ret_total = print_string(ret_total, numb);
	free(numb);
	return (ret_total);
}
