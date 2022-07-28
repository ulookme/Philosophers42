# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 15:43:00 by chajjar           #+#    #+#              #
#    Updated: 2022/07/28 11:19:17 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===------------------------=== #
#  *                          *  #
#       GLOBAL SETTINGS c        #
#  *                          *  #
# ===------------------------=== #

NAME = philo
TEST_ARGS = 1 800 200 200 7

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

ALL = parsing  main  timer_msg thread
SRC = $(addprefix $(SUBFOLDER_SRC), $(addsuffix .c, $(ALL)))
OBJ = $(SRC:.c=.o)

SUBFOLDER_SRC = src/
SUBFOLDER_OBJ = bin/

SILENT = > /dev/null 2>&1 || true

# ===------------------------=== #
#  *                          *  #
#         MAKEFILE RULES         #
#  *                          *  #
# ===------------------------=== #

all: $(NAME)

.c.o:
	@mkdir $(SUBFOLDER_OBJ) $(SILENT)
	@gcc $(FLAGS) -o $(subst $(SUBFOLDER_SRC), $(SUBFOLDER_OBJ), $@) -c $<

$(NAME): $(OBJ)
	@gcc $(DANGER) $(subst $(SUBFOLDER_SRC), $(SUBFOLDER_OBJ), $(OBJ)) -o $(NAME)

clean:
	@rm -Rf $(SUBFOLDER_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME) $(TEST_ARGS)

.PHONY: all clean fclean re test
