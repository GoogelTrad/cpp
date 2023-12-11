NAME = Violence
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

SRCS =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

OBJC = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all