SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS =	${SRCS:.c=.o}

FLAGS =	-Wall -Werror -Wextra

STD =	-std=c++98

NAME =	diamond

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