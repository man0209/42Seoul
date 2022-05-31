/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:47:50 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 12:19:46 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_values(t_info *info, char *str)
{
	int	tmp;

	tmp = ft_strchr(str, 'P');
	if (tmp)
		info->player_count += tmp;
	tmp = ft_strchr(str, 'C');
	if (tmp)
		info->coin_count += tmp;
	tmp = ft_strchr(str, 'E');
	if (tmp)
		info->exit_count += tmp;
}

void	check_walls(t_info *info, char *str, int fd)
{
	int	len;
	int	count;
	int	height;

	len = ft_strlen(str) - 1;
	count = ft_strchr(str, '1');
	height = info->height;
	if (height == 0 && (count != len))
		print_error(info, 5, fd);
	else if (height > 0 && (str[0] != '1') && (str[len - 1] != '1'))
		print_error(info, 5, fd);
}

void	read_map(t_info *info, char *file_name)
{
	int		fd;
	int		len;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	tmp = get_next_line(fd);
	info->width = ft_strlen(tmp) - 1;
	while (tmp != NULL)
	{
		len = ft_strlen(tmp) - 1;
		if (len != info->width)
		{
			free(tmp);
			print_error(info, 1, fd);
		}
		info->last_str = tmp;
		printf("%s", info->last_str);
		info->height++;
		check_values(info, tmp);
		check_walls(info, tmp, fd);
		free(tmp);
		tmp = get_next_line(fd);
	}
	printf("%d, %s, %d, %d\n", fd, info->last_str, info->height, info->width);
	printf("p : %d, c : %d, e : %d\n", info->player_count, info->coin_count, info->exit_count);
}
