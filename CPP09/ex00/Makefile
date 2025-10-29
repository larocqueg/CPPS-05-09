# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 11:08:27 by gde-la-r          #+#    #+#              #
#    Updated: 2025/10/28 11:08:37 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS = main.cpp BitcoinExchange.cpp
OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME) input.txt

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

input.txt:
	@echo "date | value\n\
2011-01-03 | 3\n\
2011-01-03 | 2\n\
2011-01-03 | 1\n\
2011-01-03 | 1.2\n\
2011-01-09 | 1\n\
2012-01-11 | 1\n\
2022-03-26 | 1\n\
2000-01-11 | 1\n\
2023-01-11 | 1\n\
\n\
2001-02-42 | 1\n\
2012-01-11 | -1\n\
2001-42-02 | 1\n\
2001-02-42 | 1\n\
2012-01-11 | 2147483648\n\
20-2001-02 | 1\n\
20-02-2001 | 1" > input.txt


clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "$(NAME) deleted"; \
	fi
	@if [ -f input.txt ]; then \
		rm input.txt; \
		echo "input.txt deleted"; \
	fi

re: fclean all

.PHONY: all clean fclean re
