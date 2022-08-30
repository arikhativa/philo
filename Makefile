# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/30 11:45:48 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD_NAME = $(notdir $(wildcard $(HEAD_DIR)/*.h))
SRC = $(notdir $(wildcard $(SRC_DIR)/*.c))


OBJ_DIR = obj
SRC_DIR = src
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

HEAD_DIR = include
HEAD =  $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -I$(HEAD_DIR)
LDLIBS = -lpthread

.PHONY: clean fclean re all

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD) $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
$(NAME): $(OBJ)
	$(CC) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
