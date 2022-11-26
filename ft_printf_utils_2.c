/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:33:11 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/26 10:38:06 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_address(void *mem)
{
	unsigned long	mem_add;
	int				total;
	char			str[17];
	size_t			i;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	total = 0;
	mem_add = (long int) mem;
	if (!mem_add)
		return (ft_putstr("0x0"));
	while (mem_add)
	{
		str[i] = base[mem_add % 16];
		mem_add /= 16;
		i++;
	}
	total += ft_putstr("0x");
	while (i-- > 0)
		total += ft_putchar_2(str[i]);
	return (total);
}

unsigned	int	ft_putnbr_u(unsigned int n)
{
	if (n <= 9)
		return (ft_putchar_2(n % 10 + '0'));
	return (ft_putnbr_u(n / 10) + ft_putchar_2(n % 10 + '0'));
}
