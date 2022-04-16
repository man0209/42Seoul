/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:48 by kokim             #+#    #+#             */
/*   Updated: 2022/04/14 15:48:51 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server	g_server;

void	ser_sighandler_connection(int signu, siginfo_t *info, void *data)
{
	(void)data;
	if (signu == SIGUSR1)
	{
		g_server.received_pid = info->si_pid;
		ft_printf("Connected Client's pid : %d\n", g_server.received_pid);
		kill(g_server.received_pid, SIGUSR1);
	}
	else
	{
		ft_printf("Send SIGUSR2\n");
		kill(g_server.received_pid, SIGUSR2);
	}
}

void	ser_sighandler_msg(int signu, siginfo_t *info, void *data)
{
	(void)data;

	if (g_server.received_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (signu == SIGUSR1)
	{
		g_server.bit += 1 << (7 - g_server.index);
	}
	if (g_server.index == 7)
	{
		write(1, &g_server.bit, 1);
	}
	if (g_server.bit == 0 && g_server.index == 7)
	{
		g_server.flag = 1;
	}
	g_server.index++;	
	if (g_server.index == 8)
	{
		g_server.index = 0;
		g_server.bit = 0;
	}
	usleep(500);
}

void	server_sa_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
}

int	main(void)
{
	ft_printf("server PID is : [ %d ] \n", getpid());
	server_sa_initialize(&g_server.ser_check_connection, &ser_sighandler_connection);
	server_sa_initialize(&g_server.ser_bit_to_msg, &ser_sighandler_msg);
	while (1)
	{
		ser_check_connection_pre();
		ser_print_msg();
	}
	return (0);
}