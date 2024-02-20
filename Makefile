# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 14:34:32 by aglanuss          #+#    #+#              #
#    Updated: 2024/02/20 12:28:20 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCLUDES = ./includes/minitalk.h

SERVER = ./src/server.c
CLIENT = ./src/client.c

FT_PRINTF = ./lib/ft_printf/libftprintf.a

all: $(NAME)

server: $(SERVER) $(FT_PRINTF) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(FT_PRINTF) $(SERVER) -o server

client: $(CLIENT) $(FT_PRINTF) $(INCLUDES) Makefile
	$(CC) $(CCFLAGS) $(FT_PRINTF) $(CLIENT) -o client

$(FT_PRINTF):
	$(MAKE) -C ./lib/ft_printf

$(NAME): $(SERVER) $(FT_PRINTF) $(CLIENT) $(INCLUDES) Makefile server client

clean:
	$(RM) client server

fclean: clean

re: fclean all

.PHONY: all clean fclean re