FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = 	main.cpp\
			Serializer.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = Serializer

all: $(NAME)

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Serializer.hpp Data.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean