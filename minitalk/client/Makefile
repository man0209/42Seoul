# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/11 13:47:37 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

CLIENT_SRC = client.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT = ../library/libft/
LILNK = -L $(LIBFT) -lft

PF = ../library/printf/
PFLNK = -L $(PF) -lftprintf

all : $(NAME)

$(NAME) : $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(LILNK) $(PFLNK) $^ -o $@

%.o : %.c 
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@$(RM) $(CLIENT_OBJ) 

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
