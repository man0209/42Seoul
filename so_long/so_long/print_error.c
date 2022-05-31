/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:12:03 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 15:52:40 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_info *info, int fd)
{
	int	len;
	int	cnt;

	len = ft_strlen(info->last_str) - 1;
	cnt = ft_strchr(info->last_str, '1');
	if (info->player_count != 1)
		print_error(info, 2, fd);
	else if (info->coin_count == 0)
		print_error(info, 3, fd);
	else if (info->exit_count == 0)
		print_error(info, 4, fd);
	else if (len != cnt)
	{
		printf("len : %d, cnt : %d, str: %s\n", len, cnt, info->last_str);
		print_error(info, 5, fd);
	}
	else if (info->height == info->width)
		print_error(info, 1, fd);
}

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
