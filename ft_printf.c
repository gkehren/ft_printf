/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:07:09 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/05 16:36:09 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(va_list params, char c)
{
	if (c == '%')
		ft_print_char('%');
	if (c == 's')
		ft_print_str((char *)va_arg(params, char *));
	if (c == 'c')
		ft_print_char(va_arg(params, int));
	if (c == 'p')
		ft_print_addr((unsigned long)va_arg(params, void *), "0123456789abcdef");
	if (c == 'd')
		ft_print_nbr(va_arg(params, int));
	if (c == 'i')
		ft_print_nbr_base(va_arg(params, int), "0123456789");
	if (c == 'u')
		ft_print_nbr_base(va_arg(params, int), "0123456789");
	if (c == 'x')
		ft_print_nbr_base(va_arg(params, int), "0123456789abcdef");
	if (c == 'X')
		ft_print_nbr_base(va_arg(params, int), "0123456789ABCDEF");
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list params;

	i = 0;
	va_start(params, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_arg(params, str[i + 1]);
			i += 2;
		}
		ft_print_char(str[i]);
		i++;
	}
	write(1, 0, 1);
	va_end(params);
	return (0);
}

#include <stdio.h>
int	main()
{
	char p[10];
	ft_printf("car: %c, number: %d, string: %s, addr: %p\n", 'x', 42, "String", p);
	printf("car: %c, number: %d, string: %s, addr: %p", 'x', 42, "String", p);
	return (0);
}
