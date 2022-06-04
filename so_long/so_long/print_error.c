/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:12:03 by kokim             #+#    #+#             */
/*   Updated: 2022/06/04 15:40:03 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_info *info)
{

	if (info->player_count != 1)
		print_error(info, 2);
	else if (info->coin_count == 0)
		print_error(info, 3);
	else if (info->exit_count != 1)
		print_error(info, 4);
	else if (info->height == info->width)
		print_error(info, 1);
}

void	print_error(t_info *info, int flag)
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
	else if (flag == 6)
		printf("Characters error!!\n");
	else if (flag == 7)
		printf("Object is surrounded!!\n");
	else if (flag == 8)
		printf("GNL error!!\n");
	free(info);
	close(info->fd);
	exit(1);
}
