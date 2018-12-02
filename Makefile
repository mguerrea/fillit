# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 14:35:22 by lbenard           #+#    #+#              #
#    Updated: 2018/12/02 14:41:51 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
RM		:= rm -rf

SRCDIR	:=	./
INCLDIR	:=	-I libft/includes
LIBDIR 	:=	libft/

CFLAGS	:=	-Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:=	-L$(LIBDIR) -lft

SRCS    :=	main.c			\
			grid.c			\
			parser.c		\
			pos.c			\
			solve.c			\
			get_next_line.c	\
			sqrt.c			\
			check_errors.c
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(patsubst %.c,%.o,$(SRCS))
DEPS	:=	Makefile functions.h
LIB		:=	$(LIBDIR)/libft.a
NAME	:=	fillit

all: $(NAME)

$(LIB):
	@$(MAKE) -C libft/

$(NAME): $(LIB) $(OBJS)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\033[32m  Cleaning: \033[0m$(OBJS)\033[0m\n"
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "fillit" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
