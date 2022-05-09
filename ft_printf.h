/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:07:21 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/09 14:18:07 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nb);
int	ft_print_nbr_u(unsigned int n);
int	ft_addr(unsigned long n);
int	ft_print_nbr_base(unsigned int n, char *base);
int	ft_printf(const char *str, ...);

#endif
