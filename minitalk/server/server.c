/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:48 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 13:42:33 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, bit_to_str);
	signal(SIGUSR2, bit_to_str);
	while (1)
		pause();
}

