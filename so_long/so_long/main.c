/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:54:18 by kokim             #+#    #+#             */
/*   Updated: 2022/05/30 16:57:08 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_init(t_info *info)
{
	info->mlx = mlx_init();
	info->str_from_map = NULL;
}


int	main(int ac, char **av)
{
	t_info *info;

	if (ac != 2)
		printf("No Map!!\n");
	info = (t_info *)malloc(sizeof(t_info));
	check_map_size(info, av[1]);
	info_init(info);
	

	system("leaks so_long");
	return (0);
}
