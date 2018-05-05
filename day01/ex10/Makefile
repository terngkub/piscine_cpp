# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 18:53:18 by nkamolba          #+#    #+#              #
#    Updated: 2018/05/05 18:54:05 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cato9tails
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
