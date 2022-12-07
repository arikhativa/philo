# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/12/07 14:47:12 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD_NAME = error_code.h \
	fork.h \
	ft_atoi.h \
	hand.h \
	input.h \
	m_value.h \
	macros.h \
	main.h \
	philo.h \
	sleep_wrapper.h \
	table.h \
	timer.h \
	util.h \

SRC = error_code.c \
	fork.c \
	ft_atoi.c \
	hand.c \
	input.c \
	input_validate.c \
	m_value.c \
	m_value2.c \
	main.c \
	philo.c \
	philo_fork.c \
	philo_handler.c \
	philo_print_action.c \
	philo_stt.c \
	philo_thread.c \
	sleep_wrapper.c \
	table.c \
	table_forks.c \
	table_philo.c \
	table_simulation1.c \
	table_simulation2.c \
	timer.c \
	util.c

OBJ_DIR = ./obj
SRC_DIR = src
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c \=.o))

HEAD_DIR = include
HEAD =  $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -I$(HEAD_DIR)
LDLIBS = -lpthread 
LDFLAGS = -L$(LIBFT_DIR)

.PHONY: clean fclean re all

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c \) $(HEAD)
	mkdir -p  $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@


t:
	@echo $(SRC)


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LDLIBS) -o $@

$(OBJ_DIR):
	@cp -a $(SRC_DIR) $(OBJ_DIR)
	@$(RM) $(OBJ:.o=.c \)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
