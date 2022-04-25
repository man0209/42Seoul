/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:46:17 by kokim             #+#    #+#             */
/*   Updated: 2021/12/07 11:08:22 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*start_point;

	start_point = (char *) s;
	while (*s)
		s++;
	if (c == '\0')
		return ((char *) s);
	while (s > start_point)
	{
		s--;
		if (*s == (char ) c)
		{
			return ((char *) s);
		}
	}
	return (0);
}
