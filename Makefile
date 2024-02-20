# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 14:34:32 by aglanuss          #+#    #+#              #
#    Updated: 2024/02/20 01:44:34 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCLUDES = ./includes/minitalk.h ./includes/utils.h

SERVER = ./src/server.c
CLIENT = ./src/client.c

UTILS = ./utils/ft_putchar.c ./utils/ft_putstr.c

all: $(NAME)

server: $(SERVER) $(UTILS) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(UTILS) $(SERVER) -o server

client: $(CLIENT) $(UTILS) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(UTILS) $(CLIENT) -o client

$(NAME): $(SERVER) $(UTILS) $(CLIENT) $(INCLUDES) Makefile server client

clean:
	$(RM) client server

fclean: clean

re: fclean all

.PHONY: all clean fclean re