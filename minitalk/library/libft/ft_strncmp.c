/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:52:21 by kokim             #+#    #+#             */
/*   Updated: 2021/12/07 14:45:47 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t			cnt;

	s1_tmp = (unsigned char *) s1;
	s2_tmp = (unsigned char *) s2;
	cnt = 0;
	if (n == 0)
		return (0);
	while (cnt < n)
	{
		if (s1_tmp[cnt] == '\0' || s2_tmp[cnt] == '\0')
			break ;
		if (s1_tmp[cnt] != s2_tmp[cnt])
			break ;
		if (cnt + 1 == n)
			break ;
		cnt++;
	}
	return ((int)(s1_tmp[cnt] - s2_tmp[cnt]));
}
