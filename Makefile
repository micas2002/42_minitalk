# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 11:53:52 by mibernar          #+#    #+#              #
#    Updated: 2022/10/03 12:50:55 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

all: $(NAME)

$(NAME): server client

bonus: server client

server: server.o libft.a
	$(CC) -o $@ $< libft.a

client: client.o libft.a
	$(CC) -o $@ $< libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft.a:
	make -C libft
	cp libft/libft.a .

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client server.o client.o libft.a
	make -C libft fclean

re: fclean all

.PHONY: all bonus libft clean fclean re