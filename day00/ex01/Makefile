# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 14:38:20 by nkamolba          #+#    #+#              #
#    Updated: 2018/04/20 18:08:12 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CLANG = clang++
FLAG = -Wall -Wextra -Werror
FILE = Contact.class.cpp main.cpp
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
