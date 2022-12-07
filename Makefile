# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/12/07 13:05:22 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD_NAME = $(notdir $(wildcard $(HEAD_DIR)/*.h))
SRC = $(notdir $(wildcard $(SRC_DIR)/*.c))

OBJ_DIR = ./obj
SRC_DIR = src
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

HEAD_DIR = include
HEAD =  $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -fsanitize=thread -I$(HEAD_DIR)
LDLIBS = -lpthread -fsanitize=thread 
LDFLAGS = -L$(LIBFT_DIR)

.PHONY: clean fclean re all

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	mkdir -p  $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDLIBS) -o $@

$(OBJ_DIR):
	@cp -a $(SRC_DIR) $(OBJ_DIR)
	@$(RM) $(OBJ:.o=.c)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
