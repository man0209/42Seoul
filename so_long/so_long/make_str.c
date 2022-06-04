/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:39:32 by kokim             #+#    #+#             */
/*   Updated: 2022/06/04 18:12:53 by kokim            ###   ########.fr       */
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

void	find_check_char(t_info *info, int index, char c, int count)
{
	int		i;
	int		tmp;
	char	*str;
	char	*upper_str;
	char	*lower_str;

	str = info->all_str[index];
	i = ft_strchr_index(str, c, index);
	upper_str = info->all_str[index - 1];
	lower_str = info->all_str[index + 1];
	while (count)
	{
		if (str[i - 1] == '1' && str[i + 1] == '1' &&\
				upper_str[i] == '1' && lower_str[i] == '1')
				print_error(info, 7);
		if (count > 1)
		{
			tmp = i;
			i = ft_strchr_index(str, c, tmp + 1);
		}
		count--;
	}
	
}

static void	check_surrounded(t_info *info)
{
	int	count;
	int	i;

	i = 1;
	while (i < info->height - 1)
	{
		count = ft_strchr(info->all_str[i], 'P');
		if (count)
			find_check_char(info, i, 'P', count);
		count = ft_strchr(info->all_str[i], 'E');
		if (count)
			find_check_char(info, i, 'E', count);
		count = ft_strchr(info->all_str[i], 'C');
		if (count)
			find_check_char(info, i, 'C', count);
		i++;
	}
}

static void	check_last_wall(t_info *info)
{
	int		len;
	int		count;
	char	*tmp;

	tmp = info->all_str[info->height - 1];
	len = ft_strlen(tmp) - 1;
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
		info->all_str[i] = (char *)malloc(sizeof(char) * (info->width + 2));
		if (info->all_str[i] == NULL)
			return ;
		tmp = get_next_line(fd);
		info->all_str[i] = tmp;
		free(tmp);
		i++;
	}
	for(int i = 0; i < info->height; i++)
	{
		printf("%c,..... all_str[%d] = %s", info->all_str[i][info->width],i, info->all_str[i]);
	}
	check_last_wall(info);
	check_surrounded(info);
	close(fd);
}

