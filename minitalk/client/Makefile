# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/06 16:41:24 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client 

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -rf

CLIENT_SRC = client.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT = ../libft/

LILNK = -lft -L$(LIBFT)

all : $(NAME)

$(NAME) : $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(LILNK) $< -o $@

%.o : %.c 
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	$(RM) $(CLIENT_OBJ) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
