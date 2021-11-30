/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:06:51 by jthor             #+#    #+#             */
/*   Updated: 2021/11/18 11:07:02 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_hex(char *set, unsigned int num);

static int	calc_total_len(unsigned int num);

static void	fill_array(unsigned int num, int size, char *ptr, char *set);

int	handle_hex(char c, int ret_total, unsigned int num)
{
	char	*set;
	char	*array;

	if (c == 'x')
		set = ft_strdup("0123456789abcdef");
	else
		set = ft_strdup("0123456789ABCDEF");
	array = ft_itoa_hex(set, num);
	ret_total = print_string(ret_total, array);
	free(array);
	free(set);
	return (ret_total);
}

static char	*ft_itoa_hex(char *set, unsigned int num)
{
	char	*ret_ptr;
	int		array_size;

	array_size = calc_total_len(num);
	ret_ptr = (char *)malloc((array_size + 1) * sizeof(char));
	if (!ret_ptr)
		return (NULL);
	fill_array(num, array_size, ret_ptr, set);
	return (ret_ptr);
}

static int	calc_total_len(unsigned int num)
{
	int	ret_val;

	if (num == 0)
		ret_val = 1;
	else
		ret_val = 0;
	while (num)
	{
		num /= 16;
		ret_val++;
	}
	return (ret_val);
}

static void	fill_array(unsigned int num, int size, char *array, char *set)
{
	int	loop_ctrl;

	loop_ctrl = 0;
	while (loop_ctrl < size)
	{
		array[size - loop_ctrl - 1] = set[num % 16];
		num /= 16;
		loop_ctrl++;
	}
	array[size] = '\0';
}
