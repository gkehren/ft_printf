/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:07:09 by gkehren           #+#    #+#             */
/*   Updated: 2022/04/24 14:52:21 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char c)
{
	/*if (c == 'c')
		ft_print_char(); // Affiche le caractère
	if (c == 's')
		ft_print_str(); // Affiche la string
	if (c == 'p')
		ft_print_addr(); // Affiche *void en hexa
	if (c == 'd')
		ft_print_dec(); // Affiche un décimal
	if (c == 'i')
		ft_print_int(); // Affiche un entier
	if (c == 'u')
		ft_print_unsigned(); // Affiche un unsigned
	if (c == 'x')
		ft_print_hex(0); // Affiche un nombre en hexa minuscule
	if (c == 'X')
		ft_print_hex(1); // Affiche un nombre en hexa majuscule*/
	if (c == '%')
		write(1, &"%", 1); // Affiche un %
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_arg(str[i + 1]);
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	ft_printf("nombre: %d", 3);
	printf("\n");
	printf("nombre: %d", 3);
	return (0);
}
