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

t_client g_client;

void	client_con_pre(int signu, siginfo_t *info, void *data)
{
	(void)signu;
	(void)data;
	if (info->si_signo == SIGUSR1)
	{
		g_client.received_pid = info->si_pid;
		ft_printf("Client : Server PID is %d\n", g_client.received_pid);
		kill(g_client.received_pid, SIGUSR1);
	}
	else
	{
		ft_printf("Not yet ready!\n");
		exit (1);
	}
}


void	seng_msg_to_server(int signu, siginfo_t *info, void *data)
{
	(void)signu;
	(void)data;
	if (info->si_signo == SIGUSR1)
	{
		
}
void server_sa_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
}

void	send_msg_to_server(pid_t pid, char *str)
{
	unsigned int	sig;
	
	int index = 0;
	while (str[index])
	{
		sig = 0;
		int i = 8;
		ft_printf("%c   ", str[index]);
		while (--i >= 0)
		{
			sig = str[index] >> i & 1 ;
			if (sig)
				kill(pid, SIGUSR1);
			else
			{
				kill(pid, SIGUSR2);
			}
			ft_printf("%d", sig);		
			usleep(1000);
		}
		ft_printf("      ");
		index++;
	}
}

void	get_server_pid(int pid)
{
	int	check;
	
	check = kill(pid, SIGUSR1);
	if (check)
	{
		ft_printf("failed\n");
		exit(1);
	}
	sigaction(SIGUSR1, &g_client.sa_cli_check_pre, NULL);
	sigaction(SIGUSR2, &g_client.sa_cli_check_pre, NULL);
	pause();
}

void	cli_send_msg_to_server(char *str)
{
	kill(g_client.received_pid, SIGUSR1);
	sigaction(SIGUSR1, &g_client.send_msg_to_server, NULL);
	sigaction(SIGUSR2, &g_client.send_msg_to_server, NULL);
	pause();
	while (*str)
	{
		send_msg_to_server(g_client.received_pid, str);
	}
	send_msg_to_server('\0');
	pause();
}

int main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !(av[2]))
		exit(1);
	pid = ft_atoi(av[1]);
	if ( pid < 100 || pid > 99998)
		exit(1);
	server_sa_initialize(&g_client.sa_cli_check_pre, &client_con_pre);
	server_sa_initialize(&g_client.sa_cli_send_msg, &send_msg_to_server);
	//server_sa_initialize(&g_client.sa_check_final, &client_con_final);
	//send_msg_to_server(pid, av[2]);

	while (1)
	{
		kill(pid, SIGUSR1);
		//send_msg_to_server(pid, av[2]);
		get_server_pid(pid);
		cli_send_msg_to_server(av[2]);
	}
}
