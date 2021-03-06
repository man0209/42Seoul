/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kim258199@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:57:38 by kokim             #+#    #+#             */
/*   Updated: 2021/12/01 16:04:17 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
