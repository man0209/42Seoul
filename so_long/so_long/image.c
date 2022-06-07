/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:31:27 by kokim             #+#    #+#             */
/*   Updated: 2022/06/07 23:27:17 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*init_img(void *mlx)
{
	t_img	*tmp;
	int		x;
	int		y;

	tmp = (t_img *)malloc(sizeof(t_img));
	if (tmp == NULL)
		return ;
	tmp->exit = mlx_xpm_file_to_image(mlx, "../images/exit_before.xpm", &x, &y);
	tmp->goal = mlx_xpm_file_to_image(mlx, "../images/goal.xpm", &x, &y);
	tmp->land = mlx_xpm_file_to_image(mlx, "../image/land.xpm", &x, &y);
	tmp->player = mlx_xpm_file_to_image(mlx, "../image/player.xpm", &x, &y);
	tmp->wall = mlx_xpm_file_to_image(mlx, "../image/wall.xpm", &x, &y);
	return (tmp);
}

static void	put_img(t_info *info, int width, int height)
{
	if (info->all_str[height][width] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->new_window, info->img->wall\
		, width * 64, height * 64);
	}
	else if (info->all_str[height][width] == 'C')
	{
		mlx_put_image_to_window(info->mlx, info->new_window, info->img->goal\
		, width * 64, height * 64);
	}
	else if (info->all_str[height][width] == 'P')
	{
		mlx_put_image_to_window(info->mlx, info->new_window, info->img->player\
		, width * 64, height * 64);
	}
	else if (info->all_str[height][width] == 'E')
	{
		mlx_put_image_to_window(info->mlx, info->new_window, info->img->exit\
		, width * 64, height * 64);
	}
	else
	{
		mlx_put_image_to_window(info->mlx, info->new_window, info->img->land\
		, width * 64, height * 64);
	}
}

void	set_image(t_info *info)
{
	int	width;
	int	height;

	height = 0;
	while (height < info->height)
	{
		width = 0;
		while (width < info->width)
		{
			put_img(info, width, height);
			width++;
		}
		height++;
	}
}