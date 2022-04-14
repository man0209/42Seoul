/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_uti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:17:59 by kokim             #+#    #+#             */
/*   Updated: 2022/04/14 15:28:54 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_request g_server;

void	ser_check_connection_pre(void)
{
	sigaction(SIGUSR1, &g_server.sa_ser_check_pre, NULL);
	sigaction(SIGUSR2, &g_server.sa_ser_check_pre, NULL);
	pause();
}

void	ser_ready_to_get_char(void)
{
	sigaction(SIGUSR1, &g_server.sa_ser_get_char, NULL);
	sigaction(SIGUSR2, &g_server.sa_ser_get_char, NULL);
	pause();
}

void	ser_print_msg(void)
{
	sigaction(SIGUSR1, &g_server.sa_ser_bit_to_msg, NULL);
	sigaction(SIGUSR2, &g_server.sa_ser_bit_to_msg, NULL);
	while (1)
	{
		pause();
		if (g_server.flag == 1)
			break;
	}
}
