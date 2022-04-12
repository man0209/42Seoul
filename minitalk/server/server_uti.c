/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_uti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:17:59 by kokim             #+#    #+#             */
/*   Updated: 2022/04/12 13:28:58 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_request g_request;

void	print_server_pid(void)
{
	ft_printf("server PID is : [ %d ] \n", getpid());
	return ;
}


