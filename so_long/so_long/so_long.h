/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:33:10 by kokim             #+#    #+#             */
/*   Updated: 2022/05/30 15:49:22 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include "../libft/libft.h"
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_info
{
	void	*mlx;
	void	*new_window;
	char	*str_from_map;
	int		height;
	int		width;
	int		player_count;
} t_info;

void	check_map_size(t_info *info, char *str);
void	info_init(t_info *info);
void	check_player(t_info *info, char *str, int fd);
#endif
