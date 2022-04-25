/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:57:06 by kokim             #+#    #+#             */
/*   Updated: 2022/04/25 13:14:54 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		length;
	int		size;
	t_node	*top;
} t_stack;

void	init_stack(t_stack *stack);


#endif