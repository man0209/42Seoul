# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/05/30 14:21:49 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

SRC = main.c check_map_size.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MLX_LNK = -L ./ -lmlx

LIBFT_DIR = ../libft/

LIBFT_LNK = -L $(LIBFT_DIR) -lft

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX_LNK) $(LIBFT_LNK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@ 
clean :
	@$(RM) $(OBJ) libmlx.dylib

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
