/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:47:50 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 15:56:53 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_values(t_info *info)
{
	int		tmp;
	char	*str;

	str = info->last_str;
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

void	check_walls(t_info *info, int fd)
{
	int		len;
	int		count;
	int		height;
	char	*str;

	len = ft_strlen(info->last_str) - 1;
	count = ft_strchr(info->last_str, '1');
	height = info->height;
	str = info->last_str;
	printf("len : %d, count : %d, height : %d\n", len, count, height);
	if (height == 0 && (count != len))
		print_error(info, 5, fd);
	else if (height > 0 && ((str[0] != '1') || (str[len - 1] != '1')))
		print_error(info, 5, fd);
	printf("str[0] : %c, str[len - 1] : %c\n", str[0], str[len - 1]);
}

void	check_rectangle(t_info *info, int fd)
{
	int	len;

	len = ft_strlen(info->last_str) - 1;
	if (info->width != len)
		print_error(info, 1, fd);
}

void	read_map(t_info *info, char *file_name)
{
	int		fd;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	tmp = get_next_line(fd);
	info->width = ft_strlen(tmp) - 1;
	while (tmp != NULL)
	{
		info->last_str = tmp;
		free(tmp);
		printf("%d, %d, %d, %s\n", fd, info->height, info->width, info->last_str);
		check_values(info);
		check_walls(info, fd);
		check_rectangle(info, fd);
		tmp = get_next_line(fd);
		info->height++;
	}
	printf("last : %s\n", info->last_str);
	check_errors(info, fd);
}
