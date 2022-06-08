# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/06/08 15:28:21 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

SRC = main.c \
	  read_map.c \
	  print_error.c     \
	  make_str.c        \
	  get_next_line.c   \
	  get_next_line_utils.c \
	  ft_strcpy.c \
	  image.c \
	  keys.c

OBJ = $(SRC:.c=.o)

MLX_DIR = ./mlx/

MLX_LNK = -L ./ -lmlx

LIBFT_DIR = ./libft/

LIBFT_LNK = -L $(LIBFT_DIR) -lft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LIBFT_LNK) $(MLX_LNK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@ 
clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJ) libmlx.dylib


fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
