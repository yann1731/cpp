SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS =	${SRCS:.c=.o}

FLAGS =	-Wall -Werror -Wextra

STD =	-std=c++98

NAME =	frag

CC =	c++

.c.o:
			${CC} ${STD} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${CC} ${STD} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@${RM} ${NAME}
re: fclean all

.PHONY: all clean re