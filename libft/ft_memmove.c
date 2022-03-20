/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kim258199@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:16 by kokim             #+#    #+#             */
/*   Updated: 2021/12/06 11:11:52 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == NULL && src == NULL)
		return (0);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (new_dst > new_src)
	{
		while (len)
		{
			len--;
			new_dst[len] = new_src[len];
		}
	}
	else
	{
		while (len)
		{
			*new_dst++ = *new_src++;
			len--;
		}
	}
	return (dst);
}
