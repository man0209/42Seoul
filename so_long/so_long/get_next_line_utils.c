/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kim258199@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:50:12 by kokim             #+#    #+#             */
/*   Updated: 2022/05/30 16:54:42 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		cnt;
	int		i;

	i = 0;
	cnt = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * cnt + 1);
	if (tmp == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	len;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * len + 1);
	if (join == NULL)
		return (0);
	while (i < len)
	{
		if (i < s1_len)
			join[i] = s1[i];
		else
			join[i] = s2[i - s1_len];
		i++;
	}
	join[i] = '\0';
	return (join);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			i++;
		s++;
	}
	if (c == '\0')
		return (0);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (0);
	while (len)
	{
		substr[i] = s[start + i];
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
