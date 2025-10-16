# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 18:43:08 by gde-la-r          #+#    #+#              #
#    Updated: 2025/10/16 18:43:12 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
