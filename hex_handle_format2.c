/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle_format2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:09:13 by kaara             #+#    #+#             */
/*   Updated: 2024/08/18 18:20:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned long x, int u)
{
	int		i;
	int		temp;
	char	*hex_digits;
	char	result[21];

	i = 0;
	temp = 0;
	if (x == 0)
		temp++, write(1, "0", 1);
	if (u)
	{
		hex_digits = "0123456789abcdef";
		while (x)
			result[i++] = hex_digits[x % 16], x = x / 16;
	}
	else
	{
		hex_digits = "0123456789ABCDEF";
		while (x)
			result[i++] = hex_digits[x % 16], x = x / 16;
	}
	result[i] = '\0';
	temp += i;
	while (i)
		write (1, &result[--i], 1);
	return (temp);
}

int	print_p(void *ptr)
{
	int				len;
	unsigned long	addr;

	len = 2;
	// if (ptr == NULL)
	// 	return (0);
	addr = (unsigned long)ptr;
	write(2, "0x", 2);
	len += print_x(addr, 1);
	return (len);
}