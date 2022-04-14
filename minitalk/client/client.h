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
	struct	sigaction	sa_cli_check_pre;
	struct	sigaction	sa_cli_send_msg;
	pid_t				received_pid;
} t_client;

#endif
