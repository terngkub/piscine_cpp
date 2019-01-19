# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 12:53:18 by                   #+#    #+#              #
#    Updated: 2019/01/13 16:24:46 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.SECONDEXPANSION:

.PHONY: all

OBJS := $(patsubst %.cpp, %.o,$(wildcard *.cpp))
HEADERS := $(wildcard *.hpp)
CXXFLAGS := -g3 -Wall -Wextra -Werror --std=c++98
LDFLAGS := -lncurses
CXX := clang++

NAME := ft_retro

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS): %.o : $(HEADERS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
