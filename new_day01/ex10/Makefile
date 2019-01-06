CC = clang++
CFLAGS = -Wall -Wextra -Werror

NAME = cato9tails
FILES = main.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(FILES:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re