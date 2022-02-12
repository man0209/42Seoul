/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:19:18 by kokim             #+#    #+#             */
/*   Updated: 2021/12/16 13:18:13 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		cnt;

	if (lst == NULL)
		return (0);
	tmp = lst;
	cnt = 0;
	while (tmp->next != NULL)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt + 1);
}
