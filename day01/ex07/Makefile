# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 18:40:06 by nkamolba          #+#    #+#              #
#    Updated: 2018/05/01 18:41:19 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CLANG = clang++
FLAG = -Wall -Wextra -Werror
FILE = main.cpp
OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CLANG) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CLANG) $(FLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
