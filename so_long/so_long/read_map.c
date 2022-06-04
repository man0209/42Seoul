/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:47:50 by kokim             #+#    #+#             */
/*   Updated: 2022/06/04 15:39:53 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_values(t_info *info, char *str)
{
	int		tmp;

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

static void	check_walls(t_info *info, char *str)
{
	int		len;
	int		count;
	int		height;

	len = ft_strlen(str) - 1;
	count = ft_strchr(str, '1');
	height = info->height;
	if (height == 0 && (count != len))
		print_error(info, 5);
	else if (height > 0 && ((str[0] != '1') || (str[len - 1] != '1')))
		print_error(info, 5);
}

static void	check_rectangle(t_info *info, char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (info->width != len)
		print_error(info, 1);
}

static void	check_values(t_info *info, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' &&\
				str[i] != 'E' && str[i] != 'P' && str[i] != '\n')  
			print_error(info, 6);
		i++;
	}
}			

void	read_map(t_info *info, char *file_name)
{
	int		fd;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		print_error(info, 8);
	info->width = ft_strlen(tmp) - 1;
	info->fd = fd;
	while (tmp != NULL)
	{
		check_values(info, tmp);
		check_walls(info, tmp);
		count_values(info, tmp);
		check_rectangle(info, tmp);
	printf("tmp : %s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
		info->height++;
	}
	check_errors(info);
	close(fd);
	make_array(info, file_name);
	printf("height : %d, width : %d\n", info->height, info->width);
}
