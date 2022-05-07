/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:07:21 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/07 15:08:16 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_print_char(char c);
void	ft_print_nbr(int nb);
void	ft_print_str(char *str);
void	ft_addr(unsigned long long nb, char *base);
void	ft_print_nbr_base(int nbr, char *base);

#endif
