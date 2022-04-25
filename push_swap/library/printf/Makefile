NAME	= libftprintf.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 

RM	= rm -f

AR	= ar
ARFLAGS	= crs

SRCS = ft_printf.c 	     \
	   ft_printf_utils.c \
	   ft_printf_hex.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
