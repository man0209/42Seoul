/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:33:36 by kokim             #+#    #+#             */
/*   Updated: 2021/12/17 20:42:26 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t		i;
	char		arr[10];
	long long	nb;	

	i = 0;
	nb = n;
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		arr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (i)
	{
		i--;
		write(fd, &arr[i], 1);
	}
}
