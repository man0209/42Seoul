/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:38 by kokim             #+#    #+#             */
/*   Updated: 2022/04/14 16:17:04 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	g_client;

void	check_connection(int signu, siginfo_t *info, void *data)
{
	(void)signu;
	(void)data;
	if (signu == SIGUSR1)
	{
		g_client.received_pid = info->si_pid;
	}
	else
	{
		ft_printf("WARNING : SIGNAL2 !! Not yet ready!\n");
		exit (1);
	}
}

void	client_sa_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
}

int main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !(av[2]))
	{
		ft_printf("error1\n");
		exit(1);
	}
	pid = atoi(av[1]);
	if ( pid < 100 || pid > 99998)
	{
		ft_printf("error2\n");
		exit(1);
	}
	ft_printf("Client's PID : %d\n", getpid());
	client_sa_initialize(&g_client.cli_check_connection, &check_connection);
	get_server_pid(pid);
	client_send_msg_to_server(pid, av[2]);
}