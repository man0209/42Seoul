# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/05/26 16:10:15 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

SRC = main.c

OBJ = $(SRC:.c=.o)

MLX = ../mlx/

MLX_LNK = -L $(MLX) -lmlx

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX_LNK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@ 
clean :
	@$(RM) $(OBJ) libmlx.dylib

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
