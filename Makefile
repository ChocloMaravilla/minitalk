#--------------#VARIABLES#--------------#
#CLIENT#
NAME_CLIENT		=		client
CLIENT_DIR		=		./src/src_client/
HEADER_CLIENT	=	$(CLIENT_DIR)client.h
SRCS_CLIENT		=		$(CLIENT_DIR)client.c
OBJS_CLIENT		=		$(SRCS_CLIENT:.c=.o)

#SERVER#
NAME_SERVER 	=		server
SERVER_DIR		=		./src/src_server/
HEADER_SERVER	=	$(SERVER_DIR)server.h
SRCS_SERVER		=		$(SERVER_DIR)server.c
OBJS_SERVER		=		$(SRCS_SERVER:.c=.o)

# #PRUEBA#
DDLB_NAME_SERVER 	=		ddlb_server
DDLB_SERVER_DIR		=		./src/src_server/
DDLB_HEADER_SERVER	=		$(SERVER_DIR)server.h
DDLB_SRCS_SERVER	=		$(SERVER_DIR)server.c
DDLB_OBJS_SERVER	=		$(SRCS_SERVER:.c=.o)

#LIBFT#
LIBFT_DIR = 		Libs/libft/
LIBFT	=			$(LIBFT_DIR)libft.a

#PRINTF#
PRINT_DIR = 		Libs/ft_printf/
PRINTF	=			$(PRINT_DIR)libftprintf.a

#LIBS#
LIBS	=			./Libs/

#REGULAR#
CC	= 				cc
RM	= 				rm -f
FLAGS	=  			-Wall -Wextra -Werror
#--------------#REGLAS#-----------------#
all: $(NAME_CLIENT) $(NAME_SERVER)
	
$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
$(PRINTF):
	@make -C $(PRINT_DIR) --no-print-directory

$(NAME_CLIENT): ${OBJS_CLIENT} $(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(LIBFT) $(PRINTF) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): ${OBJS_SERVER} $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $(PRINTF) $(LIBFT) $(OBJS_SERVER) -o $(NAME_SERVER)

$(DDLB_NAME_SERVER): $(DDLB_OBJS_SERVER) $(PRINTF) $(LIBFT)
	@gcc $(FLAGS) -g $(PRINTF) $(LIBFT) $(DDLB_OBJS_SERVER) -o $(DDLB_NAME_SERVER)
#----------#REGLAS PREDEFINIDAS#-----------#
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINT_DIR)
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(DDLB_OBJS_SERVER)

fclean: clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(DDLB_NAME_SERVER)--no-print-directory

ddlb: $(DDLB_NAME_SERVER)

re: fclean all

#------------#PHONY#-----------#
.PHONY: all clean fclean re client server ddlb
