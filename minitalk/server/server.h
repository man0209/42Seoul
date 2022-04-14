/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:32 by kokim             #+#    #+#             */
/*   Updated: 2022/04/14 15:28:02 by kokim            ###   ########.fr       */
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
	struct sigaction	sa_ser_check_pre;
	struct sigaction	sa_ser_get_char;
	struct sigaction	sa_ser_bit_to_msg;
	pid_t				received_pid;
	int					index;
	int					bit;
	int					flag;
}	t_request;

/* 전역 변수 내 시그널 핸들러, 시그널 집합 등 설정 */
void	server_sa_initialize(struct sigaction *sa, \
		void (*f)(int, siginfo_t *, void *));
void	ser_check_connection_pre(void);
void	ser_ready_to_get_char(void);
void	ser_print_msg(void);


#endif
