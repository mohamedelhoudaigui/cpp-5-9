SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

HEAD = Bureaucrat.hpp

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
