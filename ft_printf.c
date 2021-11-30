/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:58:39 by jthor             #+#    #+#             */
/*   Updated: 2021/11/01 17:58:42 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		ret_total;
	va_list	ap;

	ret_total = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ret_total = conversion_handle(ret_total, *str, ap);
		}
		else
			ret_total = print_char(ret_total, *str);
		str++;
	}
	va_end(ap);
	return (ret_total);
}
