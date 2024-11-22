SRCS =	ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_unsignd.c ft_printhex.c ft_putstr.c ft_printp.c
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

r: all clean

.PHONY : all clean fclean re
