# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:52:27 by chajjar           #+#    #+#              #
#    Updated: 2022/07/14 13:36:49 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===------------------------=== #
#  *                          *  #
#         GLOBAL SETTINGS        #
#  *                          *  #
# ===------------------------=== #

NAME = philo
TEST_ARGS = 10 410 200 200

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

ALL = parsing philo main thread
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