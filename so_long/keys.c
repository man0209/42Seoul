/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:34:37 by kokim             #+#    #+#             */
/*   Updated: 2022/06/08 11:55:25 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_game(t_info *info)
{
	int	i;

	i = 0;
	printf("Congratulations! You got all Coins!! Bye\n");
	while (i < info->height)
	{
		free(info->all_str[i]);
		i++;
	}
	free(info->all_str);
	exit (0);
}	

void	move_w(t_info *info)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < info->height)
	{
		i = ft_strchr_index(info->all_str[height], 'P', 0);
		if (i)
			break ;
		height++;
	}
	if (info->all_str[height - 1][i] == 'C')
		info->coin_count--;
	if (info->all_str[height - 1][i] == 'E' && info->coin_count == 0)
		clear_game(info);
	else if (info->all_str[height - 1][i] != '1' && \
			info->all_str[height - 1][i] != 'E')
	{
		info->all_str[height - 1][i] = 'P';
		info->all_str[height][i] = '0';
		info->walk_count++;
		printf("Walk_count : %d\n", info->walk_count);
		set_image(info);
	}
}

void	move_a(t_info *info)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < info->height)
	{
		i = ft_strchr_index(info->all_str[height], 'P', 0);
		if (i)
			break ;
		height++;
	}
	if (info->all_str[height][i - 1] == 'C')
		info->coin_count--;
	if (info->all_str[height][i - 1] == 'E' && info->coin_count == 0)
		clear_game(info);
	else if (info->all_str[height][i - 1] != '1' && \
			info->all_str[height][i - 1] != 'E')
	{
		info->all_str[height][i - 1] = 'P';
		info->all_str[height][i] = '0';
		info->walk_count++;
		printf("Walk_count : %d\n", info->walk_count);
		set_image(info);
	}
}

void	move_s(t_info *info)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < info->height)
	{
		i = ft_strchr_index(info->all_str[height], 'P', 0);
		if (i)
			break ;
		height++;
	}
	if (info->all_str[height + 1][i] == 'C')
		info->coin_count--;
	if (info->all_str[height + 1][i] == 'E' && info->coin_count == 0)
		clear_game(info);
	else if (info->all_str[height + 1][i] != '1' && \
			info->all_str[height + 1][i] != 'E')
	{
		info->all_str[height + 1][i] = 'P';
		info->all_str[height][i] = '0';
		info->walk_count++;
		printf("Walk_count : %d\n", info->walk_count);
		set_image(info);
	}
}

void	move_d(t_info *info)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < info->height)
	{
		i = ft_strchr_index(info->all_str[height], 'P', 0);
		if (i)
			break ;
		height++;
	}
	if (info->all_str[height][i + 1] == 'C')
		info->coin_count--;
	if (info->all_str[height][i + 1] == 'E' && info->coin_count == 0)
		clear_game(info);
	else if (info->all_str[height][i + 1] != '1' && \
			info->all_str[height][i + 1] != 'E')
	{
		info->all_str[height][i + 1] = 'P';
		info->all_str[height][i] = '0';
		info->walk_count++;
		printf("Walk_count : %d\n", info->walk_count);
		set_image(info);
	}
}
