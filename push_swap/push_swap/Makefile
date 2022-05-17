# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/05/17 17:26:25 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

SRC = push_swap.c check_argv.c free_utils.c ft_split.c check_str.c ss_pa.c \
	  rr.c rra.c sort_upto_five.c  sort_utils.c sort_big.c get_max.c \
	  array_utils.c

OBJ = $(SRC:.c=.o)

FT = ../library/printf/
FTLNK = -L $(FT) -lftprintf

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(FTLNK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
