/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:33:10 by kokim             #+#    #+#             */
/*   Updated: 2022/05/31 12:09:36 by kokim            ###   ########.fr       */
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
	char	*last_str;
	int		height;
	int		width;
	int		player_count;
	int		coin_count;
	int		exit_count;
}	t_info;

void	read_map(t_info *info, char *file_name);
void	info_init(t_info *info, char *file_name);
void	check_values(t_info *info, char *str);
void	check_walls(t_info *info, char *str, int fd);
void	print_error(t_info *info, int flag, int fd);
#endif
