/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:02 by kokim             #+#    #+#             */
/*   Updated: 2022/04/11 14:07:34 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"

typedef struct s_minitalk
{
	struct sigaction	a;
	struct sigaction	b;
	struct sigaction	c;
	pid_t				clipid;
	pid_t				srvpid;
	int					index;
	char				msg;
}	t_minitalk;

#endif
