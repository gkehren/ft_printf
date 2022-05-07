/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:23:00 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/07 15:06:14 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c)
{
	write(1, &c, 1);
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

void	ft_addr(unsigned long long nb, char *base)
{
	unsigned long	result;
	unsigned long	diviseur;
	unsigned long	size_base;

	ft_print_str("0x");
	size_base = ft_strlen(base);
	diviseur = 1;
	while ((nb / diviseur) >= size_base)
		diviseur = diviseur * size_base;
	while (diviseur > 0)
	{
		result = (nb / diviseur) % size_base;
		ft_print_char(base[result]);
		diviseur = diviseur / size_base;
	}
}

void	ft_print_nbr_base(int nbr, char *base)
{
	long	n;
	char	tab[32];
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		n = nbr;
		n = -n;
		ft_print_char('-');
	}
	else
		n = nbr;
	i = 0;
	while (n > 0)
	{
		tab[i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	while (--i >= 0)
		ft_print_char(tab[i]);
}

void	ft_print_nbr(int nb)
{
	long	i;

	i = nb;
	if (i < 0)
	{
		ft_print_char('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_print_nbr(i / 10);
		ft_print_nbr(i % 10);
	}
	else
	{
		ft_print_char(i + '0');
	}
}

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}
