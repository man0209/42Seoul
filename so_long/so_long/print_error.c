/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:12:03 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 11:54:55 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_info *info, int flag, int fd)
{
	if (flag == 1)
		printf("not rectangle!!!\n");
	else if (flag == 2)
		printf("Player error!!\n");
	else if (flag == 3)
		printf("Coin error!!\n");
	else if (flag == 4)
		printf("Exit error!!\n");
	else if (flag == 5)
		printf("Wall error!!\n");
	free(info);
	close(fd);
	exit(1);
}
