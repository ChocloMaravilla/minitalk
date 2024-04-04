SRCSSERVER = src/src_server/server.c
SRCSCLIENT = src/src_client/client.c
OBJSSERVER = ${SRCSSERVER:.c=.o}
OBJSCLIENT = ${SRCSCLIENT:.c=.o}
NAMESERVER = server
NAMECLIENT = client
CC = gcc
RM = rm -f
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror
.c.o: ${CC} ${CFLAGS} -I ./src/src_header/minitalk.h  -c $< -o ${<:.c=.o}
all:		${OBJSSERVER} ${OBJSCLIENT}
			$(MAKE) -C ./Libs/ft_printf
			$(MAKE) -C ./Libs/libft
			${CC} ${CFLAGS} ${SRCSSERVER} -o ${NAMESERVER} ./Libs/ft_printf/libftprintf.a ./Libs/libft/libft.a
			${CC} ${CFLAGS} ${SRCSCLIENT} -o ${NAMECLIENT} ./Libs/ft_printf/libftprintf.a ./Libs/libft/libft.a
clean:		
			$(MAKE) clean -C ./Libs/ft_printf
			$(MAKE) clean -C ./Libs/libft
			# ${RM} ${OBJSSERVER} ${OBJSCLIENT}
fclean:		clean
			$(MAKE) fclean -C ./Libs/ft_printf
			$(MAKE) fclean -C ./Libs/libft
			${RM} ${NAMESERVER} ${NAMECLIENT}
re:			fclean all
.PHONY: all clean fclean re