/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:23:40 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 12:37:44 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pfchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_pfstr(char *s, int *count)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		*count += 1;
	}
}

void	ft_pfnbr(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		ft_pfstr("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_pfchar('-', count);
	}
	if (nbr > 9)
		ft_pfnbr(nbr / 10, count);
	ft_pfchar((nbr % 10) + '0', count);
	return ;
}

void	ft_putnbr_u(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_pfnbr(nbr / 10, count);
	ft_pfchar((nbr % 10) + '0', count);
	return ;
}

/*
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	i = ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
	j = printf(" NULL %s NULL ", NULL);
	printf("\n");
	printf("i : %d, j : %d\n", i, j);
	printf("\n");
	k = ft_printf(" %p %p ", 0, 0);
	printf("\n");
	l = printf(" %p %p ", 0, 0);
	printf("\n");
	printf("k : %d, l : %d\n", k, l);
	return 0;
}
*/
