/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:02 by kokim             #+#    #+#             */
/*   Updated: 2022/04/14 15:40:14 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"

typedef struct	c_request
{
	struct	sigaction	cli_check_connection;
	struct	sigaction	cli_check_char;
	struct	sigaction	check_msg_to_server;
	pid_t				received_pid;
} t_client;

void check_connection(int signu, siginfo_t *info, void *data) ;
void client_sa_initialize(struct sigaction *sa,\
void (*f)(int, siginfo_t *, void *));
void send_msg_to_server(char c);
void client_check_char(int signu, siginfo_t *info, void *data);
void check_msg_to_server(int signu, siginfo_t *info, void *data);
void get_server_pid(int pid);
void client_send_msg_to_server(pid_t pid, char *str);

#endif
