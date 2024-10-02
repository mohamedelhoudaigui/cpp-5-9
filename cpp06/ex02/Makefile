SRCS = main.cpp Base.cpp Funcs.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Base.hpp Funcs.hpp

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = Identify

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