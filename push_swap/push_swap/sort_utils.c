/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:02:51 by kokim             #+#    #+#             */
/*   Updated: 2022/05/18 10:22:12 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest_a(t_stack *a, t_stack *b)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = a->top;
	while (tmp != a->tail)
	{
		if (tmp->index == get_min_index(a))
		{
			if (index > (a->length) / 2)
			{
				while (tmp->prev != a->head)
					rra(a, 0);
			}
			else
			{
				while (tmp->prev != a->head)
					ra(a, 0);
			}
			pb(b, a);
			return ;
		}
		index++;
		tmp = tmp->next;
	}
}
