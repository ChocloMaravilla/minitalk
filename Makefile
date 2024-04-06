SRCSSERVER = src/src_server/server.c
SRCSCLIENT = src/src_client/client.c

LIBFT = ./Libs/libft/libft.a
PRINTF = ./Libs/ft_printf/libftprintf.a 

OBJSCLIENT = ${SRCSCLIENT:.c=.o}
OBJSSERVER = ${SRCSSERVER:.c=.o}

NAMESERVER = server
NAMECLIENT = client

CC = gcc
RM = rm -f
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror

%.o: %.c  
	${CC} ${CFLAGS} -I ./src/src_header/minitalk.h  -c $< -o ${<:.c=.o}

all: dir $(NAMECLIENT) $(NAMESERVER)

dir:
	$(MAKE) -C ./Libs/ft_printf --no-print-directory
	$(MAKE) -C ./Libs/libft --no-print-directory

$(NAMESERVER): $(OBJSSERVER) ./src/src_header/minitalk.h $(PRINTF) $(LIBFT) Makefile
	${CC} ${CFLAGS} ${OBJSSERVER} -o ${NAMESERVER} ./Libs/ft_printf/libftprintf.a ./Libs/libft/libft.a
	
$(NAMECLIENT): $(OBJSCLIENT) ./src/src_header/minitalk.h $(PRINTF) $(LIBFT) Makefile
	${CC} ${CFLAGS} ${OBJSCLIENT} -o ${NAMECLIENT} ./Libs/ft_printf/libftprintf.a ./Libs/libft/libft.a

clean:		
			$(MAKE) clean -C ./Libs/ft_printf
			$(MAKE) clean -C ./Libs/libft
			${RM} ${OBJSSERVER} ${OBJSCLIENT}
fclean:		clean
			$(MAKE) fclean -C ./Libs/ft_printf
			$(MAKE) fclean -C ./Libs/libft
			${RM} ${NAMESERVER} ${NAMECLIENT}
re:			fclean all
.PHONY: all clean fclean re