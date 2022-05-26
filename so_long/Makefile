# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 12:53:27 by kokim             #+#    #+#              #
#    Updated: 2022/05/26 15:09:37 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

SO_LONG_DIR = ./so_long/

MLX_DIR = ./mlx/

all :
	@make -C $(MLX_DIR)
	@make -C $(SO_LONG_DIR)
	@echo "$(NAME) was compiled!!"

clean :
	@make -C $(MLX_DIR) clean
	@make -C $(SO_LONG_DIR) clean
	@echo "$(NAME)'s object files was deleted!!"

fclean : 
	@make -C $(MLX_DIR) fclean
	@make -C $(SO_LONG_DIR) fclean
	@echo "$(NAME) was deleted!!"

re : fclean all

.PHONY : all clean fclean re
