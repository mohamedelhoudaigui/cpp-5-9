SRCS = RPN.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = RPN.hpp

CC = cpp -std=c++98

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean