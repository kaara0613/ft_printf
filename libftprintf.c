/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:59:27 by kaara             #+#    #+#             */
/*   Updated: 2024/08/18 15:19:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_par(const char *format, va_list *args);

int	ft_printf(const char *format, ...)
{
	int		total_len;
	va_list	args;

	total_len = 1;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				total_len += check_par(format, &args);
		}
		else
		{
			write(1, format, 1);
			total_len++;
		}
		format++;
	}
	va_end(args);
	return (total_len - 1);
}

int	check_par(const char *format, va_list *args)
{
	int total_len;

	total_len = 0;
	if (*format == 'c')
		total_len += print_c(va_arg(*args, int));
	else if (*format == 's')
		total_len += print_s(va_arg(*args, char *));
	else if (*format == 'p')
		total_len += print_p(va_arg(*args, void *));
	else if (*format == 'd' || *format == 'i')
		total_len += print_d_i(va_arg(*args, int));
	else if (*format == 'u')
		total_len += print_u(va_arg(*args, unsigned int));
	else if (*format == 'x')
		total_len += print_x(va_arg(*args, unsigned int), 1);
	else if (*format == 'X')
		total_len += print_x(va_arg(*args, unsigned int), 0);
	else if (*format == '%')
	{
		write(1, "%", 1);
		total_len++;
	}
	return (total_len);
}
