/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:47:50 by kokim             #+#    #+#             */
/*   Updated: 2022/05/30 17:05:45 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_info *info, char *str, int fd)
{
	int	tmp;

	tmp = ft_strchr(str, 'P');
	printf("tmp : %d\n", tmp);
	if (tmp == 0)
	{
		return ;
	}
	else if (tmp > 1 || info->player_count > 1)
	{
		printf("Error!! more than one player\n");
		free(info);
		close(fd);
		exit(1);
	}
	(info->player_count)++;
	(info->width)++;
}

void	check_map_size(t_info *info, char *str)
{
	int		fd;
	char	*tmp;

	fd = open("./test.ber", O_RDONLY);
	tmp = get_next_line(fd);
	info->width = ft_strlen(tmp) - 1;
	while (tmp != NULL)
	{
		printf("%s", tmp);
		info->height++;
		check_player(info, tmp, fd);
		free(tmp);
		tmp = get_next_line(fd);
	}
	printf("%d, %s, %d, %d\n", fd, str, info->height, info->width);
}
