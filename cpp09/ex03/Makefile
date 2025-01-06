SRCS = PmergeMe.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = PmergeMe.hpp

CC = c++ 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = PmergeMe

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
