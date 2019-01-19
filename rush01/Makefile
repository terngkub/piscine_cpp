CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCS = -I ~/.brew/include
LIBS = -l ncurses -L ~/.brew/lib -l sfml-graphics -l sfml-window -l sfml-system
RPATH = -Wl,-rpath,$$HOME/.brew/lib

NAME = ft_gkrellm
FILES = main.cpp Monitor.cpp \
		IMonitorModule.cpp Dummy.cpp \
		IMonitorDisplay.cpp Shell.cpp Graphic.cpp\

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(FILES:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBS) $(RPATH) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
