/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:30 by kokim             #+#    #+#             */
/*   Updated: 2022/05/02 20:28:07 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	count_word(char const *s, char c)
{
	size_t	cnt;
	size_t	flag;
	size_t	i;

	cnt = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			cnt ++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (cnt);
}

static char	*split_and_allocate(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **words, size_t len)

{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**words_small(char const *s, char c, char **words_big)
{
	size_t	start;
	size_t	i;
	size_t	small_i;

	i = 0;
	small_i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		words_big[small_i] = split_and_allocate(s + start, i - start);
		if (words_big[small_i] == NULL)
		{
			free_all(words_big, small_i);
			return (0);
		}
		small_i++;
	}
	words_big[small_i] = NULL;
	return (words_big);
}

char	**ft_split(char const *s, char c)
{
	char			**words_big;
	size_t			small_cnt;

	if (s == NULL)
		return (0);
	small_cnt = count_word(s, c);
	words_big = (char **)malloc(sizeof(char *) * (small_cnt + 1));
	if (words_big == NULL)
		return (0);
	words_big = words_small(s, c, words_big);
	if (words_big == NULL)
		return (0);
	return (words_big);
}
