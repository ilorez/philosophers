# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 16:06:35 by znajdaou          #+#    #+#              #
#    Updated: 2025/03/03 17:32:05 by znajdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c	utils 

BUILD_DR = ./build/
NAME =	philo 

FLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread #-g #-g3 #
INCLUDES_DRS = -I./includes  
CC = cc
RM = rm -f

SRCS= philo.c init_data.c init_forks.c\
			on_error.c  \
			ft_atol.c ft_isdigit.c ft_isspace.c \
			ft_calloc.c ft_pututils.c \
			print_msg_status.c utils.c ft_memcpy.c \
			ft_errno.c \
			threads_creature.c watcher.c \
			philo_life_cycle.c philo_utils.c

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c ./includes/philo.h ./includes/t_errno.h | $(BUILD_DR) 
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
