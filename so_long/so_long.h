/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:33:10 by kokim             #+#    #+#             */
/*   Updated: 2022/06/08 13:58:27 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "./libft/libft.h"
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_img
{
	void	*exit;
	void	*goal;
	void	*land;
	void	*player;
	void	*wall;
}	t_img;

typedef struct s_info
{
	void	*mlx;
	void	*new_window;
	t_img	img;
	char	**all_str;
	int		height;
	int		width;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		walk_count;
	int		fd;
}	t_info;

void	read_map(t_info *info, char *file_name);
void	print_error(t_info *info, int flag);
void	check_errors(t_info *info);
char	*ft_strjoin_with_no_lines(t_info *info, char *str);
void	cut_all_str(t_info *info);
void	make_array(t_info *info, char *file_name);
void	ft_strcpy(char *dst, const char *src);
t_img	init_img(void *mlx);
int		ft_strchr_index(const char *s, int c, int index);
void	move_d(t_info *info);
void	move_s(t_info *info);
void	move_a(t_info *info);
void	move_w(t_info *info);
void	set_image(t_info *info);
int		exit_game(t_info *info);
int		press_key(int key_code, t_info *info);
void	free_all_str(t_info *info, int flag);
#endif
