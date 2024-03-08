# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 14:34:32 by aglanuss          #+#    #+#              #
#    Updated: 2024/03/08 12:14:40 by aglanuss         ###   ########.fr        #
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

UTILS = ./utils/ft_isdigit.c ./utils/ft_strlen.c ./utils/ft_atoi.c \
				./utils/ft_itoa.c ./utils/ft_joinchar.c

all: $(NAME)

server: $(SERVER) $(FT_PRINTF) $(INCLUDES) $(UTILS) Makefile
	$(CC) $(CCFLAGS) $(FT_PRINTF) $(UTILS) $(SERVER) -o server

client: $(CLIENT) $(FT_PRINTF) $(INCLUDES) $(UTILS) Makefile
	$(CC) $(CCFLAGS) $(FT_PRINTF) $(UTILS) $(CLIENT) -o client

$(FT_PRINTF):
	$(MAKE) -C ./lib/ft_printf

$(NAME): $(SERVER) $(FT_PRINTF) $(CLIENT) $(INCLUDES) $(UTILS) Makefile server client

clean:
	$(RM) client server

fclean: clean

re: fclean all

.PHONY: all clean fclean re