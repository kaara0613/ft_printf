/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:48:38 by kaara             #+#    #+#             */
/*   Updated: 2024/12/03 18:05:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_c(int c);
int	print_s(char *str);
int	print_d_i(int di);
int	print_i(int i);
int	print_u(unsigned int u);
int	print_x(unsigned long x, int u);
int	print_p(void *ptr);
int	printf_putnbr(int n);
int	check_par(const char *format, va_list *args);
int	ft_printf(const char *format, ...);

#endif
