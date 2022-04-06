/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:02 by kokim             #+#    #+#             */
/*   Updated: 2022/04/06 15:42:36 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_request
{
	struct sigaction	phase_send_connection;
	struct sigaction	phase_send_msglen;
	struct sigaction	phase_send_msg;
	pid_t				clipid;
	pid_t				srvpid;
	int					len;
	char				*msg;
}	t_request;

#endif
