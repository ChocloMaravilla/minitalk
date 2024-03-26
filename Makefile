#--------------#VARIABLES#--------------#

HEADER_CLIENT	=	client.h
HEADER_SERVER	=	server.h
NAME_CLIENT	=	client
SRCS_CLIENT	=	src/src_client/client.c
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)
NAME_SERVER =	server
SRCS_SERVER	=	src/src_server/server.c
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
LIBFT_DIR = ./Libs/libft/
LIBFT	=	$(LIBFT_DIR)libft.a
PRINT_DIR = ./Libs/ft_printf/
PRINTF	=	$(PRINTF_DIR)libftprintf.a
CC	= 	cc
RM	= 	rm -f
FLAGS	=  -Wall -Wextra -Werror

#--------------#REGLAS#-----------------#
all:
	@make -C $(LIBFT_DIR) --no-print-directory
	@make client
	@make server

%.o : %.c Makefile ${HEADER_CLIENT}
	${CC} ${FLAGS} -I $(LIBS) -c $< -o $@

%.o : %.c Makefile ${HEADER_SERVER}
	${CC} ${FLAGS} -I $(LIBS) -c $< -o $@

$(NAME_CLIENT): ${OBJS_CLIENT}
	$(CC) $(FLAGS) $(LIBFT) $(PRINTF) $(OBJS_CLIENT) -o $(NAME_CLIENT) 

$(NAME_SERVER): ${OBJS_SERVER}
	$(CC) $(FLAGS) $(LIBFT) $(PRINTF) $(OBJS_SERVER) -o $(NAME_SERVER)

#----------#REGLAS PREDEFINIDAS#-----------#
clean:
	@make clean -C $(LIBFT_DIR)
	@
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) --no-print-directory

re: fclean all

#----------#REGLAS EXECUTABLES#-----------#
client: $(NAME_CLIENT)

server: $(NAME_SERVER)


#------------#PHONY#-----------#
.PHONY: all clean fclean re client server
