/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:59:08 by kaara             #+#    #+#             */
/*   Updated: 2024/08/18 01:50:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *str)
{
	int	len;
	
	len = 0;
	if (str == NULL)
	{
		len = 6, write(1, "(null)", len);
		return(len);
	}
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	print_d_i(int di)
{
	int				i;
	int				temp;
	unsigned int	un;
	char			result[12];

	i = 0;
	temp = 0;
	if (di == 0)
		temp++, write(1, "0", 1);
	if (di < 0)
	{
		temp++, write(1, "-", 1);
		un = (unsigned int)-di;
	}
	else
		un = (unsigned int)di;
	while (un)
	{
		result[i++] = un % 10 + '0';
		un /= 10;
	}
	temp += i;
	while (i > 0)
		write(1, &result[--i], 1);
	return (temp);
}

int	print_u(unsigned int u)
{
	int		i;
	int		temp;
	char	result[10];

	i = 0;
	temp = 0;
	if (u == 0)
		temp++, write(1, "0", 1);
	while (u)
	{
		result[i++] = u % 10 + '0';
		u /= 10;
	}
	temp += i;
	while (i > 0)
		write(1, &result[--i], 1);
	return (temp);
}

// int	printf_putnbr(int n)
// {
// 	int				i;
// 	int				temp;
// 	unsigned int	un;
// 	char			result[12];

// 	i = 0;
// 	if (n == 0)
// 		write(1, "0", 1);
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		un = (unsigned int)-n;
// 	}
// 	else
// 		un = (unsigned int)n;
// 	while (un)
// 	{
// 		result[i++] = un % 10 + '0';
// 		un /= 10;
// 	}
// 	temp = i;
// 	while (i > 0)
// 		write(1, &result[--i], 1);
// 	return (temp);
// }