# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 14:34:32 by aglanuss          #+#    #+#              #
#    Updated: 2024/02/19 13:56:32 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCLUDES = ./includes/minitalk.h

SERVER = ./src/server.c
CLIENT = ./src/client.c

all: $(NAME)

server: $(SERVER) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(SERVER) -o server

client: $(CLIENT) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(CLIENT) -o client

$(NAME): $(SERVER) $(CLIENT) $(INCLUDES) Makefile server client

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
