/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:54:18 by kokim             #+#    #+#             */
/*   Updated: 2022/05/27 14:47:56 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_init(t_info *info)
{
	info->mlx = mlx_init();
	info->new_window
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_A)
		param->y++;
	else if (keycode == KEY_D)
		param->y--;
	else if (keycode == KEY_ESC)
		exit (0);
	printf("(x,y) : (%d, %d)\n", param->x, param->y);
	return (0);
}

int	main(int ac, char **av)
{
	t_info info;

	if (ac != 2)
		printf("No Map!!\n");
	info = (t_info)malloc(sizeof(t_info));
	info_init(&info);
	

	return (0);
}
