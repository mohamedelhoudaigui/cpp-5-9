SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Span.hpp

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = span

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