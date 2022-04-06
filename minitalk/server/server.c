/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:48 by kokim             #+#    #+#             */
/*   Updated: 2022/04/06 16:43:18 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	bit_to_str(int sig)
{
	static	int	i;
	static	int	bit;

	if (sig == SIGUSR1)
		ft_putstr("hi\n");
	i++;
	if (i == 8)
	{
		ft_putchar(bit);
		i = 0;
		bit = 0;
	}
}

int	main()
{
	pid_t	pid;

	pid = getpid();

	ft_putstr("pid : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, bit_to_str);
	signal(SIGUSR2, bit_to_str);
	while (1)
		pause();
}

