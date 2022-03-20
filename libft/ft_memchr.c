/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kim258199@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:21:06 by kokim             #+#    #+#             */
/*   Updated: 2021/12/08 09:36:31 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	tmp_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*tmp_s == (unsigned char) c)
			return ((void *) tmp_s);
		tmp_s++;
		i++;
	}
	return (0);
}
