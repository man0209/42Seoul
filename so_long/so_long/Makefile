# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/06/07 23:34:25 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

SRC = main.c read_map.c \
	  print_error.c     \
	  make_str.c        \
	  get_next_line.c   \
	  get_next_line_utils.c \
	  ft_strcpy.c \
	  image.c \
	  keys.c

OBJ = $(SRC:.c=.o)

MLX_LNK = -L ./ -lmlx

LIBFT_DIR = ../libft/

LIBFT_LNK = -L $(LIBFT_DIR) -lft

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS)  $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@ 
clean :
	@$(RM) $(OBJ) libmlx.dylib

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
