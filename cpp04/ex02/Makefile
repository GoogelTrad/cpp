NAME = Animal
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

SRCS =	main.cpp \
		Animal.cpp \
		Brain.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \
		

OBJC = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all