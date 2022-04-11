# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/11 13:46:05 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

SERVER_SRC = server.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

LIBFT = ../library/libft/ 
LFLNK = -L $(LIBFT) -lft

FT = ../library/printf/
FTLNK = -L $(FT) -lftprintf

all : $(NAME)

$(NAME) : $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(LFLNK) $(FTLNK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@$(RM) $(SERVER_OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
