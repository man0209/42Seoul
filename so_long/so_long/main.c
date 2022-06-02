/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:54:18 by kokim             #+#    #+#             */
/*   Updated: 2022/06/02 20:00:53 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_init(t_info *info, char *file_name)
{
	info->mlx = mlx_init();
	info->all_str = NULL;
	info->upper_str = NULL;
	info->middle_str = NULL;
	info->lower_str = NULL;
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
	printf("\nlast check : %s, len : %d", info->all_str, ft_strlen(info->all_str));
	//system("leaks so_long");
	return (0);
}
