/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:59:52 by kaara             #+#    #+#             */
/*   Updated: 2024/08/18 18:22:13 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int main(void)
{
    int len = 0;
    int ft_len = 0;

	len = printf("%p", "");
    printf("\n%d", len);
    printf("\n");
    ft_len = ft_printf("%p", "");
    printf("\n%d", ft_len);
    return (0);
}
