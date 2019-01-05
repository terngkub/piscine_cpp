CC = clang++
CFLAGS = -Wall -Wextra -Werror

NAME = account
FILES = tests.cpp Account.class.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(FILES:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re