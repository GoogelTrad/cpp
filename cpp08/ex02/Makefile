NAME = mutant
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

SRCS =	main.cpp \

OBJC = ${SRCS:.cpp=.o}

.cpp.o:
	c++ $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all