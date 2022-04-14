/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:38 by kokim             #+#    #+#             */
/*   Updated: 2022/04/12 13:57:03 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>
#include <unistd.h>

void	send_msg_to_server(pid_t pid, char *str)
{
	unsigned int	sig;
	
	int index = 0;
	while (str[index])
	{
		sig = 0;
		int i = 8;
		printf("%c", str[index]);
		while (--i >= 0)
		{
			sig = str[index] >> i & 1 ;
			if (sig)
				kill(pid, SIGUSR1);
			else
			{
				kill(pid, SIGUSR2);
			}
			
			printf("%d", sig);		
			usleep(1000);
		}
		printf("      ");
		index++;
	}
}

int main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !(av[2]))
		exit(1);
	pid = atoi(av[1]);
	if ( pid < 100 || pid > 99998)
		exit(1);
	send_msg_to_server(pid, av[2]);
}
