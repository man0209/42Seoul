/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_uti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:03:13 by kokim             #+#    #+#             */
/*   Updated: 2022/04/16 11:54:27 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	g_client;

void	get_server_pid(int pid)
{
	int	check;

	check = kill(pid, SIGUSR1);
	if (check)
	{
		ft_printf("failed\n");
		exit(1);
	}
	sigaction(SIGUSR1, &g_client.cli_check_connection, NULL);
	sigaction(SIGUSR2, &g_client.cli_check_connection, NULL);
	pause();
}

void	str_to_bit(pid_t pid, char c)
{
	unsigned int	sig;
	int				i;

	sig = 0;
	i = 8;
	ft_printf("%c   ", c);
	while (--i >= 0)
	{
		sig = c >> i & 1;
		if (sig)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		ft_printf("%d", sig);
		usleep(500);
	}
	ft_printf("      ");
}

void	client_send_msg_to_server(pid_t pid, char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		str_to_bit(pid, str[index++]);
	}
	str_to_bit(pid, '\0');
}
