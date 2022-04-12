/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:32 by kokim             #+#    #+#             */
/*   Updated: 2022/04/12 16:03:10 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"

typedef struct s_request
{
	struct sigaction	sa_ready;
	struct sigaction	sa_char;
	struct sigaction	sa_bit;
	pid_t				clipid;
	pid_t				srvpid;
}	t_request;

/* 서버 pid 출력 */
void	print_server_pid(void);
/* 전역 변수 내 시그널 핸들러, 시그널 집합 등 설정 */
void	server_sa_initialize(struct sigaction *sa, \
		void (*f)(int, siginfo_t *, void *));

#endif
