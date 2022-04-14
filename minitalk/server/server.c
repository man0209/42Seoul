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
#include <stdio.h>
#include <unistd.h>

t_request	g_server;

// 10진수 -> 2진수 변환 (재귀적 버전)
void ten_to_two_j(int n)
{
	if (n < 2)
	{ // n==1 (이전 n이 2이거나 3)
		printf("%d", n);
	}
	else
	{
		ten_to_two_j(n / 2);
		printf("%d", n % 2);
	}
}

void print_server_pid(void)
{
	printf("server PID is : [ %d ] \n", getpid());
	return;
}

void	bit_to_msg(int signu, siginfo_t *info, void *data)
{
	(void)data;
	(void)signu;

	g_server.received_pid = info->si_pid;
	//printf("g_request.client_pid : %d\n", g_server.received_pid); //ft_ 로 수정
	if ()
	//kill(g_server.received_pid, SIGUSR1);
	if (signu == SIGUSR1)
	{
		g_server.bit += 1 << (7 - g_server.index);
	}
	g_server.index++;

	if (g_server.index == 8)
	{
		//ten_to_two_j(g_server.bit);
		//printf("\n ");
		write(1, &g_server.bit, 1);
		//printf("  ");
		g_server.index = 0;
		g_server.bit = 0;
	}	
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


int	main(void)
{
	print_server_pid();
	server_sa_initialize(&g_server.sa_bit_to_msg, &bit_to_msg);	

	sigaction(SIGUSR1, &g_server.sa_bit_to_msg, NULL);
	sigaction(SIGUSR2, &g_server.sa_bit_to_msg, NULL);

	while (1)
	{
		pause();
	}
}

