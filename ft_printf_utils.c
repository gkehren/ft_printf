/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:23:00 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/07 18:05:11 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_return_addr(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_return_addr(n / 16, hex);
	i += write(1, hex + (n % 16), 1);
	return (i);
}

int	ft_addr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	ft_print_char('0');
	ft_print_char('x');
	i += ft_return_addr(n, hex);
	return (i);
}

int	ft_print_nbr_base(unsigned int n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_nbr_base(n / 16, base);
	len += write(1, (base + (n % 16)), 1);
	return (len);
}

int	ft_print_nbr(int nb)
{
	long	i;
	int		len;

	len = 0;
	i = nb;
	if (i < 0)
	{
		len = ft_print_char('-');
		i *= -1;
	}
	if (i > 9)
	{
		len += ft_print_nbr(i / 10);
		len += ft_print_nbr(i % 10);
	}
	else
		len += ft_print_char(i + '0');
	return (len);
}

int	ft_print_nbr_u(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n > 9)
		ret += ft_print_nbr_u(n / 10);
	ret += ft_print_char((n % 10) + '0');
	return (ret);
}

int	ft_print_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
		len += write(1, &str[i++], 1);
	return (len);
}
