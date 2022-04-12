/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:48 by kokim             #+#    #+#             */
/*   Updated: 2022/04/12 16:02:43 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_request	g_server;

void	ser_sighandler_ready(int signu, siginfo_t *info, void *data)
{
	(void)data;
	(void)signu;
	if (signu == SIGUSR1)
	{
		g_server.clipid = info->si_pid;
		ft_printf("g_request.client_pid : %d\n", g_server.clipid);
		kill(g_server.clipid, SIGUSR1);
	}
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
	print_server_pid();
	server_sa_initialize(&g_server.sa_ready, &ser_sighandler_ready);
	sigaction(SIGUSR1, &g_server.sa_a, NULL);
	while (1)
	{
		pause();
	}
}

