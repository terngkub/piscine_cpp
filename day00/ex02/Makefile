NAME = account
CLANG = clang++
FLAG = -Wall -Wextra -Werror
FILE = tests.cpp Account.class.cpp
OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CLANG) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re