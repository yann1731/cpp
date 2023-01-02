SRCS =	main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS =	${SRCS:.c=.o}

FLAGS =	-Wall -Werror -Wextra

STD =	-std=c++98

NAME =	bsp

CC =	c++

.c.o:
			${CC} ${STD} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${CC} ${STD} ${FLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@${RM} ${NAME}
re: fclean all

.PHONY: all clean re