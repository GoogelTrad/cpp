NAME = btc
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

SRCS =	main.cpp \
		BitcoinExchange.cpp \

OBJC = ${SRCS:.cpp=.o}

all: ${NAME}

.cpp.o:
	c++ $(CFLAGS) -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all