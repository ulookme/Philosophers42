# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 12:48:17 by chajjar           #+#    #+#              #
#    Updated: 2022/07/18 12:50:20 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# ===------------------------=== #
#  *                          *  #
#       GLOBAL SETTINGS c        #
#  *                          *  #
# ===------------------------=== #

NAME = philo
TEST_ARGS = 50 300 100 200 20

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

ALL = parsing philo main thread output
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
