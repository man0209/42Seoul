/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kim258199@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:49:16 by kokim             #+#    #+#             */
/*   Updated: 2022/06/02 13:36:49 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static int	free_backup(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
		return (1);
	}
	return (0);
}

static char	*print_line(char **backup)
{
	char	*line;
	char	*new_backup;
	int		index;

	if (**backup == 0)
	{
		free_backup(backup);
		return (0);
	}
	index = find_newline(*backup) + 1;
	line = ft_substr(*backup, 0, index);
	if (line == 0)
		return (0);
	new_backup = ft_substr(*backup, index, (ft_strlen(*backup) - (index)));
	if (new_backup == 0)
	{
		free(line);
		return (0);
	}
	free_backup(backup);
	*backup = new_backup;
	return (line);
}

static int	add_backup(char **backup, int fd, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (bytes != 0 && !ft_strchr(*backup, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free_backup(&buffer);
			free_backup(backup);
			return (0);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(*backup, buffer);
		if (temp == 0)
			return (0);
		free_backup(backup);
		*backup = temp;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (backup == 0)
		backup = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	if (!(add_backup(&backup, fd, buffer)))
		return (0);
	free_backup(&buffer);
	return (print_line(&backup));
}
