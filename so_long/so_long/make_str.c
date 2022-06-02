/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:39:32 by kokim             #+#    #+#             */
/*   Updated: 2022/06/02 20:00:46 by kokim            ###   ########.fr       */
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

char	*ft_strjoin_with_no_lines(t_info *info, char *str)
{
	char	*tmp;
	char	*result;

	if (info->all_str == 0)
		info->all_str = ft_strdup("");
	tmp = info->all_str;
	free(info->all_str);
	result = ft_strjoin(tmp, str);
	return (result);
}


static void	check_surrounded(t_info *info, char c)
{
	char	*upper;
	char	*middle;
	char	*lower;
	int		count;
	int		i;

	upper = info->upper_str;
	middle = info->middle_str;
	lower = info->lower_str;
	count = ft_strchr(middle, c);
	i = ft_strchr_index(middle, c, 1);
	while (count)
	{
		if (middle[i - 1] == '1' && middle[i + 1] == '1' &&\
					upper[i] == '1' && lower[i] == '1')
				print_error(info, 7);
		printf("[i - 1] : %c, [i + 1] : %c, [i] : %c, [i] : %c\n", middle[i-1], middle[i+1], upper[i], lower[i]);
		if (count > 1)
			i = ft_strchr_index(middle, c, i);
		count--;
	}
}


void	cut_all_str(t_info *info)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (i < (info->height))
	{
		if (i % 3 == 0)
		{
			info->upper_str = ft_substr(info->all_str, index, info->width);
		}
		else if (i % 3 == 1)
		{
			info->middle_str = ft_substr(info->all_str, index, info->width);
		}
		else if (i % 3 == 2)
		{
			info->lower_str = ft_substr(info->all_str, index, info->width);
		}
		index += (info->width + 1);
		/* upper, middle, lower filled */
		if (i % 3 == 0 && i != 0)
		{
			check_surrounded(info, 'P');
			check_surrounded(info, 'E');
			check_surrounded(info, 'C');
		}
		i++;
	}
}
