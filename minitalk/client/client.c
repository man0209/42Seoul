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
#include <stdio.h>
#include <stdlib.h>

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
		printf("WARNING : SIGNAL2 !! Not yet ready!\n");
		exit (1);
	}
}

void get_server_pid(int pid)
{
	int check;
	
	check = kill(pid, SIGUSR1);
	if (check)
	{
		printf("failed\n");
		exit(1);
	}
	sigaction(SIGUSR1, &g_client.cli_check_connection, NULL);
	sigaction(SIGUSR2, &g_client.cli_check_connection, NULL);
	pause();
}

void client_sa_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
}

void str_to_bit(pid_t pid, char c)
{
	unsigned int sig;
	int i;

	sig = 0;
	i = 8;
	printf("%c   ", c);
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
		printf("%d", sig);
		usleep(1000);
	}
	printf("      ");
}

void client_send_msg_to_server(pid_t pid, char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		str_to_bit(pid, str[index++]);
	}
	str_to_bit(pid, '\0');
}

int main(int ac, char **av)
{
	pid_t	pid;


	if (ac != 3 || !(av[2]))
	{
		printf("errer\n");
		exit(1);
	}
	pid = atoi(av[1]);
	if ( pid < 100 || pid > 99998)
	{
		printf("errpr\n");
		exit(1);
	}
	printf("Client's PID : %d\n", getpid());
	client_sa_initialize(&g_client.cli_check_connection, &check_connection);
	get_server_pid(pid);
	client_send_msg_to_server(pid, av[2]);
}
