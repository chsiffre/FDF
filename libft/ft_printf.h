/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:25:48 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/24 15:21:39 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int			ft_putstr(char *s);
int			ft_putchar_2(int c);
int			ft_conv_hex(long int c, char *base);
int			ft_putnbr_2(int c);
int			ft_conv_address(void *mem);
unsigned	int	ft_putnbr_u(unsigned int n);
int			ft_printf(const char *s, ...);
int			ft_printf_2(va_list args, char c);

#endif
