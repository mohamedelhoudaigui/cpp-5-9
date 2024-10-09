SRCS = main.cpp Bureaucrat.cpp Form.cpp

HEADERS = Bureaucrat.hpp Form.hpp

OBJS = $(SRCS:.cpp=.o)

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = Form

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean