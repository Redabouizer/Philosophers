# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 10:17:48 by rbouizer          #+#    #+#              #
#    Updated: 2024/08/28 17:36:47 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/utils.c \
		src/algo.c \
		src/init.c \
		src/init_pro.c \
		src/main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address -g
CC = cc
RM = rm -rf

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all