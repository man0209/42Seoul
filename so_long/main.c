/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:54:18 by kokim             #+#    #+#             */
/*   Updated: 2022/06/08 15:14:11 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	info_init(t_info *info, char *file_name)
{
	info->mlx = mlx_init();
	info->all_str = NULL;
	info->img = init_img(info->mlx);
	info->height = 0;
	info->width = 0;
	info->walk_count = 0;
	info->player_count = 0;
	info->coin_count = 0;
	info->exit_count = 0;
	info->fd = 0;
	read_map(info, file_name);
	info->new_window = mlx_new_window(info->mlx, info->width * 64, \
	info->height * 64, "so_long");
	set_image(info);
}

int	exit_game(t_info *info)
{
	int	i;

	i = 0;
	printf("you pressed down ESC OR Red BTN \n");
	mlx_destroy_window(info->mlx, info->new_window);
	while (i < info->height)
	{
		free(info->all_str[i]);
		i++;
	}
	free(info->all_str);
	exit (0);
}

int	press_key(int key_code, t_info *info)
{
	if (key_code == KEY_W)
		move_w(info);
	else if (key_code == KEY_A)
		move_a(info);
	else if (key_code == KEY_S)
		move_s(info);
	else if (key_code == KEY_D)
		move_d(info);
	else if (key_code == KEY_ESC)
		exit_game(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
	{
		printf("No Map!!\n");
		return (1);
	}
	info = (t_info *)malloc(sizeof(t_info));
	info_init(info, av[1]);
	mlx_hook(info->new_window, 2, 0, &press_key, info);
	mlx_hook(info->new_window, 17, 0, &exit_game, info);
	mlx_loop(info->mlx);
	return (0);
}
