/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:08:46 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 11:28:45 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	check_specifier(const char *format, va_list ap, int *return_val);
void	ft_pfchar(char c, int *count);
void	ft_pfnbr(int n, int *count);
void	ft_pfstr(char *s, int *count);
void	ft_putaddr(unsigned long long nbr, int *count);
void	ft_puthex(unsigned long long nbr, int *count, const char format);
void	ft_putnbr_u(unsigned int nbr, int *count);
void	ft_putnbr_u(unsigned int nbr, int *count);

#endif
