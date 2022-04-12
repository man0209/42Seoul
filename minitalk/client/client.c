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
/*
void	send_str_to_server(pid_t pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	bit = 7;
	while (str[i])
	{
		while (bit >= 0)
		{
			if ((str[i] >> 7) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			bit--;
		}
		i++;
	}
}
*/


int main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !(av[2]))
		exit(1);
	pid = ft_atoi(av[1]);
	if ( pid < 100 || pid > 99998)
		exit(1);
	//send_str_to_server(pid, av[2]);
	ft_printf("clipid : %d\n", getpid());
	kill (pid, SIGUSR1);
}
