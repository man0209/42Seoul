# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/06 16:42:42 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

SERVER_SRC = server.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

LIBFT = ../libft/
LFLNK = -lft -L$(LIBFT)

all : $(NAME)

$(SERVER) : $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(LFLNK) $< -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@$(RM) $(SERVER_OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
