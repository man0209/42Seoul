/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:13:20 by kokim             #+#    #+#             */
/*   Updated: 2021/12/17 20:32:33 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	len;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return ((char *) s2);
	if (s2 == NULL)
		return ((char *) s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * len + 1);
	if (join == NULL)
		return (0);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			join[i] = s1[i];
		else
			join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = '\0';
	return (join);
}
