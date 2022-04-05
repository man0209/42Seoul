# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/04 14:13:04 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(SERVER) $(CLIENT)

CLIENT = client

SERVER = server

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

CLIENT_SRC = client.c

SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

all : $(NAME)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
