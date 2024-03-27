SRCS	= main.cpp ScalarConverter.cpp

OBJS	= ${SRCS:.cpp=.o}
CXX	= c++
RM	= rm -f
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= convert

${NAME}: ${OBJS}
				${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all