/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:54:18 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 15:36:02 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_init(t_info *info, char *file_name)
{
	info->mlx = mlx_init();
	info->last_str = NULL;
	info->height = 0;
	info->width = 0;
	info->player_count = 0;
	info->coin_count = 0;
	info->exit_count = 0;
	read_map(info, file_name);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
		printf("No Map!!\n");
	info = (t_info *)malloc(sizeof(t_info));
	info_init(info, av[1]);
	//system("leaks so_long");
	return (0);
}
