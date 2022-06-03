/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:39:32 by kokim             #+#    #+#             */
/*   Updated: 2022/06/04 01:16:05 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strchr_index(const char *s, int c, int index)
{
	int	i;

	i = index;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

void	find_check_char(t_info *info, int index, char c)
{
	int	i;
	int	count;

	i = index;
	count = ft_strchr(info->all_str[i], c);
	while (count)
	{
		//한 줄에 코인이 한 개 이상일 때 첫번째 코인을 확인 후 두번 째 코인 확인하는 방법
	}
	
}

void	check_surrounded(t_info *info)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < info->height - 1)
	{
		find_check_char(info, i, 'P');
	}
}

void	check_last_wall(t_info *info)
{
	int		len;
	int		count;
	char	*tmp;

	tmp = info->all_str[info->height - 1];
	len = ft_strlen(tmp);
	count = ft_strchr(tmp, '1');
	if (len != count)
		print_error(info, 5);
}

void	make_array(t_info *info, char *file_name)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	info->all_str = (char **)malloc(sizeof(char *) * info->height);
	if (info->all_str == NULL)
		return ;
	while (i < info->height)
	{
		/* 개행 + \0 */
		info->all_str[i] = (char *)malloc(sizeof(char) * info->width + 2);
		if (info->all_str[i] == NULL)
			return ;
		tmp = get_next_line(fd);
		info->all_str[i] = tmp;
		free(tmp);
		i++;
	}
	check_last_wall(info);
	close(fd);
}

