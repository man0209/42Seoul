/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:32 by kokim             #+#    #+#             */
/*   Updated: 2022/04/16 11:49:01 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"

typedef struct s_request
{
	struct sigaction	ser_check_connec;
	struct sigaction	ser_bit_to_msg;
	pid_t				received_pid;
	int					index;
	int					bit;
	int					flag;
}	t_server;

void	ser_sighandler_connec(int signu, siginfo_t *info, void *data);
void	ser_sighandler_msg(int signu, siginfo_t *info, void *data);
void	ser_sa_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *));
void	ser_check_connection_pre(void);
void	ser_print_msg(void);

#endif
