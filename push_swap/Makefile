# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/25 12:28:31 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

PUSH_SWAP_DIR = ./push_swap/

PFDIR = ./library/printf/

all :
	@$(MAKE) -C $(PFDIR)
	@$(MAKE) -C $(PUSH_SWAP_DIR)
	@echo " $(NAME) was compiled!!"

bonus :
	@$(MAKE) -C $(PFDIR) bonus
	@$(MAKE) -C $(PUSH_SWAP_DIR) bonus
	@echo " $(NAME) bonus was compiled!!"

clean :
	@$(MAKE) -C $(PFDIR) clean
	@$(MAKE) -C $(PUSH_SWAP_DIR) clean
	@echo " $(NAME)'s object files was deleted!!"

fclean : 
	@$(MAKE) -C $(PFDIR) fclean
	@$(MAKE) -C $(PUSH_SWAP_DIR) fclean
	@echo " $(NAME) was deleted!!"

re : fclean all

.PHONY : all clean fclean re
