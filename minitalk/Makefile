# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokim <kokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:11:14 by kokim             #+#    #+#              #
#    Updated: 2022/04/11 13:11:40 by kokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk 

CLIDIR = ./client/

SERDIR = ./server/

LFDIR = ./library/libft/

PFDIR = ./library/printf/

all :
	@$(MAKE) -C $(LFDIR)
	@$(MAKE) -C $(PFDIR)
	@$(MAKE) -C $(CLIDIR)
	@$(MAKE) -C $(SERDIR)
	@echo " $(NAME) was compiled!!"

bonus :
	@$(MAKE) -C $(LFDIR) bonus
	@$(MAKE) -C $(PFDIR) bonus
	@$(MAKE) -C $(CLIDIR) bonus
	@$(MAKE) -C $(SERDIR) bonus
	@echo " $(NAME) bonus was compiled!!"

clean :
	@$(MAKE) -C $(LFDIR) clean
	@$(MAKE) -C $(PFDIR) clean
	@$(MAKE) -C $(CLIDIR) clean
	@$(MAKE) -C $(SERDIR) clean
	@echo " $(NAME)'s object files was deleted!!"

fclean : 
	@$(MAKE) -C $(LFDIR) fclean
	@$(MAKE) -C $(PFDIR) fclean
	@$(MAKE) -C $(CLIDIR) fclean
	@$(MAKE) -C $(SERDIR) fclean
	@echo " $(NAME) was deleted!!"

re : fclean all

.PHONY : all clean fclean re
