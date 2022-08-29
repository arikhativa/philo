# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/29 12:21:09 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = ./src
SRC = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

HEAD_DIR = ./include
HEAD_NAME = $(notdir $(wildcard $(HEAD_DIR)/*.h))
HEAD =  $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -I$(HEAD_DIR)
#LDFLAGS =
LDLIBS = -lpthread

.PHONY: clean fclean re all

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $^ $(LDLIBS) -o $@
#$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
