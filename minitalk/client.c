/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:38 by kokim             #+#    #+#             */
/*   Updated: 2022/04/05 15:19:05 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // 지우기

int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long			minus;
	unsigned long long	result;

	minus = 1;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result > 9223372036854775807 && minus == 1)
			return (-1);
		else if (result > 9223372036854775807 && minus == -1)
			return (0);
		str++;
	}
	return ((int)(result * minus));
}

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
			if ((str[i] >>> 7) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			bit--;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !(av[2]))
		exit(1);
	pid = ft_atoi(av[1]);
	if ( pid < 100 || pid > 100000)
		exit(1);
	send_str_to_server(pid, av[2]);
	// av[2] 를 kill함수를 이용해 av[1] pid 를 가진 서버로 전송하는 함수를 만들자.

	// av[1] = pid, av[2] 이후부터는 문자열
	// 받은 문자열 ft_atoi함수로 정수로 바꿔서 전송.
	// pid 받으면 kill 함수로 해당 pid 로 시그널 전송.
}
