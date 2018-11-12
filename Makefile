# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:49:08 by mguerrea          #+#    #+#              #
#    Updated: 2018/11/12 15:55:36 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fillit
SOURCES	=	main.c		\
			grid.c		\
			parser.c	\
			pos.c		\
			solve.c		\
			get_next_line.c	\
			sqrt.c
OBJECTS	=	$(SOURCES:.c=.o)
LIBFT	=	libft/libft.a

all: $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBFT) $(CFLAGS)

.c.o: $(SOURCES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
