/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:44:32 by kokim             #+#    #+#             */
/*   Updated: 2021/12/20 09:39:57 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cp;
	size_t	start;
	size_t	end;

	start = 0;
	if (s1 == NULL)
		return (0);
	if (set == NULL)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end && ft_strchr(set, s1[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	cp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (cp == NULL)
		return (0);
	ft_strlcpy(cp, s1 + start, end - start + 1);
	return (cp);
}
