/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:19:23 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 11:29:21 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(const char *format, va_list ap, int *return_val)
{
	int	temp;

	temp = 0;
	temp = *return_val;
	if (*format == 'i' || *format == 'd')
		ft_pfnbr(va_arg(ap, int), &temp);
	else if (*format == 'c')
		ft_pfchar((char)va_arg(ap, int), &temp);
	else if (*format == 's')
		ft_pfstr(va_arg(ap, char *), &temp);
	else if (*format == '%')
		ft_pfchar('%', &temp);
	else if (*format == 'p')
	{
		ft_pfstr("0x", &temp);
		ft_putaddr(va_arg(ap, unsigned long long), &temp);
	}
	else if (*format == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), &temp);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(ap, unsigned int), &temp, *format);
	else
		return ;
	*return_val = temp;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printf_return_val;

	printf_return_val = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			check_specifier(++format, ap, &printf_return_val);
		else
			ft_pfchar(*format, &printf_return_val);
		format++;
	}
	va_end(ap);
	return (printf_return_val);
}
