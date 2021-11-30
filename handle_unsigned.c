/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:01:29 by jthor             #+#    #+#             */
/*   Updated: 2021/11/01 18:01:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_unsigned(unsigned int numb);

static int	calc_total_len(unsigned int n);

static void	fill_array(unsigned int n, int numb_len, char *retptr);

int	handle_unsigned(int ret_total, unsigned int numb)
{
	char	*numb_conv;

	numb_conv = ft_itoa_unsigned(numb);
	ret_total = print_string(ret_total, numb_conv);
	free(numb_conv);
	return (ret_total);
}

static char	*ft_itoa_unsigned(unsigned int numb)
{
	int		numb_len;
	char	*ret_ptr;

	numb_len = calc_total_len(numb);
	ret_ptr = (char *)malloc((numb_len + 1) * sizeof(char));
	if (!ret_ptr)
		return (NULL);
	fill_array(numb, numb_len, ret_ptr);
	return (ret_ptr);
}

static int	calc_total_len(unsigned int n)
{
	int	ret_val;

	if (n >= 0 && n <= 9)
		return (1);
	ret_val = 0;
	while (n)
	{
		n /= 10;
		ret_val++;
	}
	return (ret_val);
}

static void	fill_array(unsigned int n, int numb_len, char *ret_ptr)
{
	int	loop_ctrl;

	loop_ctrl = 0;
	while (loop_ctrl < numb_len)
	{
		ret_ptr[numb_len - loop_ctrl - 1] = "0123456789"[n % 10];
		n /= 10;
		loop_ctrl++;
	}
	ret_ptr[numb_len] = '\0';
}
