SRCS = ft_putnbr.c ft_putchar.c ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rc
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o : %.c libftprintf.h
	${CC} ${CFLAGS} -c $< -o $@
all : ${NAME}

${NAME} = ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all