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

t_server	g_server;

void	ser_check_connection_pre(void)
{
	sigaction(SIGUSR1, &g_server.ser_check_connection, NULL);
	sigaction(SIGUSR2, &g_server.ser_check_connection, NULL);
	pause();
}

void	ser_print_msg(void)
{
	sigaction(SIGUSR1, &g_server.ser_bit_to_msg, NULL);
	sigaction(SIGUSR2, &g_server.ser_bit_to_msg, NULL);
	while (1)
	{
		pause();
		if (g_server.flag == 1)
		{
			g_server.flag = 0;
			break;
		}
	}
}
