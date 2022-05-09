# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/05/06 00:00:35 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

SRC = push_swap.c check_argv.c free_utils.c ft_split.c check_str.c commands.c \
	  sort_upto_five.c  sort_utils.c

OBJ = $(SRC:.c=.o)

FT = ../library/printf/
FTLNK = -L $(FT) -lftprintf

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
