/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:07:33 by jthor             #+#    #+#             */
/*   Updated: 2021/11/18 11:07:36 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_ptr(unsigned long num);

static int	calc_total_len(unsigned long num);

static void	fill_array(unsigned long num, int size, char *ptr);

int	handle_ptr(int ret_total, unsigned long num)
{
	char	*array;

	if (num == 0)
	{
		ret_total = print_string(ret_total, "0x0");
		return (ret_total);
	}
	array = ft_itoa_ptr(num);
	ret_total = print_string(ret_total, array);
	free(array);
	return (ret_total);
}

static char	*ft_itoa_ptr(unsigned long num)
{
	char	*ret_ptr;
	int		array_size;

	array_size = calc_total_len(num);
	ret_ptr = (char *)malloc((array_size + 1) * sizeof(char));
	if (!ret_ptr)
		return (NULL);
	fill_array(num, array_size, ret_ptr);
	return (ret_ptr);
}

static int	calc_total_len(unsigned long num)
{
	int	ret_val;

	ret_val = 2;
	while (num)
	{
		num /= 16;
		ret_val++;
	}
	return (ret_val);
}

static void	fill_array(unsigned long num, int size, char *array)
{
	int	loop_ctrl;

	loop_ctrl = 0;
	array[0] = '0';
	array[1] = 'x';
	while (loop_ctrl < size - 2)
	{
		array[size - loop_ctrl - 1] = "0123456789abcdef"[num % 16];
		num /= 16;
		loop_ctrl++;
	}
	array[size] = '\0';
}
