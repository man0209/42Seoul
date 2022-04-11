/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:57:41 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 11:31:27 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long nbr, int *count, const char format)
{
	char	*hex_str;

	hex_str = "0123456789abcdef";
	if (format == 'X')
		hex_str = "0123456789ABCDEF";
	if (nbr > 15)
		ft_puthex(nbr / 16, count, format);
	ft_pfchar(hex_str[nbr % 16], count);
}

void	ft_putaddr(unsigned long long nbr, int *count)
{
	char	*hex_str;

	hex_str = "0123456789abcdef";
	if (nbr == 0)
	{
		write(1, "0", 1);
		*count += 1;
		return ;
	}
	if (nbr > 15)
		ft_putaddr(nbr / 16, count);
	ft_pfchar(hex_str[nbr % 16], count);
}
