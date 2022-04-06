/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:32 by kokim             #+#    #+#             */
/*   Updated: 2022/04/06 14:17:51 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H 
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

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
