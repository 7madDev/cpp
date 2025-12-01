FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = 	main.cpp\
			ScalarConverter.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = ScalarConverter

all: $(NAME)

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean