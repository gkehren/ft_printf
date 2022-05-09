/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:07:09 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/09 14:18:28 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(va_list params, char c)
{
	int		len;

	len = 0;
	if (c == '%')
		len += ft_print_char('%');
	if (c == 's')
		len += ft_print_str((char *)va_arg(params, char *));
	if (c == 'c')
		len += ft_print_char(va_arg(params, int));
	if (c == 'p')
		len += ft_addr((unsigned long)va_arg(params, void *));
	if (c == 'd')
		len += ft_print_nbr(va_arg(params, int));
	if (c == 'i')
		len += ft_print_nbr(va_arg(params, int));
	if (c == 'u')
		len += ft_print_nbr_u(va_arg(params, int));
	if (c == 'x')
		len += ft_print_nbr_base(va_arg(params, int), "0123456789abcdef");
	if (c == 'X')
		len += ft_print_nbr_base(va_arg(params, int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_print_arg(params, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(params);
	return (len);
}
