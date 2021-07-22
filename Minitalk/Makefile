
NAME	= server
NAME1	= client

LIST	= 	ft_server.c
LIST1	= 	ft_client.c

INC_DIR	=	/includes

OBJS	=	$(patsubst %.c, %.o, $(LIST))

OBJS1	=	$(patsubst %.c, %.o, $(LIST1))

CC		= gcc

CFLAGS	=	-Werror -Wall -Wextra

LIBFT	=	libft/libft.a

all	: runlib	$(NAME)

runlib:
	@make -C libft/

$(NAME): $(LIST)
	$(CC) $(CFLAGS) $(LIBFT) $(LIST) -I.$(INC_DIR) -o $(NAME)


client:	$(LIST1)
	$(CC) $(CFLAGS) $(LIBFT) $(LIST1) -I.$(INC_DIR) -o $(NAME1)

clean:
		$(MAKE) clean -C libft/
		@rm -f $(OBJS) $(OBJS1)

fclean:	clean
		@rm -f $(NAME) $(NAME1) $(LIBFT)
		$(MAKE) fclean -C libft/

re:		fclean all client

.PHONY:	all client clean fclean re
