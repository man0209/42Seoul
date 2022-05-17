/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:16:21 by kokim             #+#    #+#             */
/*   Updated: 2022/05/16 23:44:16 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	array_ascending(t_stack *a, int *arr)
{
	int	i;
	int	j;
	int	tmp;
	
	i = 0;
	while (i < a->length)
	{
		j = i + 1;
		while (j < a->length)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp; 
			}
			j++;
		}
		i++;
	}
}

static void	set_a_index(t_stack *a, int *arr)
{
	int		i;
	t_node	*tmp;
	
	i = 0;
	while (i < a->length)
	{
		tmp = a->top;
		while (tmp)
		{
			if (tmp->data == arr[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void	array_converter(t_stack *a, int *arr)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (i < a->length)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	array_ascending(a, arr);
	set_a_index(a, arr);
	free(arr);
}