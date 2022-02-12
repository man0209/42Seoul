/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:45:34 by kokim             #+#    #+#             */
/*   Updated: 2021/12/13 12:48:29 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	long long		num;
	size_t			len;

	if (n == 0)
		return (1);
	len = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*itos(char *str, long long nb, size_t len)
{
	while (nb > 0)
	{
		str[len--] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	nb;

	nb = n;
	len = n_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		itos(str, nb, len);
	}
	if (nb > 0)
		itos(str, nb, len);
	return (str);
}
