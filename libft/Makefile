# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:02:14 by lbenard           #+#    #+#              #
#    Updated: 2018/11/19 11:34:33 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	srcs/ft_memset.c			\
				srcs/ft_bzero.c				\
				srcs/ft_memcpy.c			\
				srcs/ft_memccpy.c			\
				srcs/ft_memmove.c			\
				srcs/ft_memchr.c			\
				srcs/ft_memcmp.c			\
				srcs/ft_strlen.c			\
				srcs/ft_strdup.c			\
				srcs/ft_strcpy.c			\
				srcs/ft_strncpy.c			\
				srcs/ft_strcat.c			\
				srcs/ft_strncat.c			\
				srcs/ft_strlcat.c			\
				srcs/ft_strchr.c			\
				srcs/ft_strrchr.c			\
				srcs/ft_strstr.c			\
				srcs/ft_strnstr.c			\
				srcs/ft_strcmp.c			\
				srcs/ft_strncmp.c			\
				srcs/ft_atoi.c				\
				srcs/ft_isalpha.c			\
				srcs/ft_isdigit.c			\
				srcs/ft_isalnum.c			\
				srcs/ft_isascii.c			\
				srcs/ft_isprint.c			\
				srcs/ft_toupper.c			\
				srcs/ft_tolower.c			\
				srcs/ft_memalloc.c			\
				srcs/ft_memdel.c			\
				srcs/ft_strnew.c			\
				srcs/ft_strdel.c			\
				srcs/ft_strclr.c			\
				srcs/ft_striter.c			\
				srcs/ft_striteri.c			\
				srcs/ft_strmap.c			\
				srcs/ft_strmapi.c			\
				srcs/ft_strequ.c			\
				srcs/ft_strnequ.c			\
				srcs/ft_strsub.c			\
				srcs/ft_strjoin.c			\
				srcs/ft_strtrim.c			\
				srcs/ft_strsplit.c			\
				srcs/ft_itoa.c				\
				srcs/ft_putchar.c			\
				srcs/ft_putstr.c			\
				srcs/ft_putendl.c			\
				srcs/ft_putnbr.c			\
				srcs/ft_putchar_fd.c		\
				srcs/ft_putstr_fd.c			\
				srcs/ft_putendl_fd.c		\
				srcs/ft_putnbr_fd.c			\
				srcs/ft_lstnew.c			\
				srcs/ft_lstdelone.c			\
				srcs/ft_lstdel.c			\
				srcs/ft_lstadd.c			\
				srcs/ft_lstiter.c			\
				srcs/ft_lstmap.c			\
				srcs/ft_strndup.c			\
				srcs/ft_isspace.c			\
				srcs/ft_isupper.c			\
				srcs/ft_islower.c			\
				srcs/ft_strnlen.c			\
				srcs/ft_abs.c				\
				srcs/ft_min.c				\
				srcs/ft_max.c				\
				srcs/ft_nblen.c				\
				srcs/ft_lststrjoin.c		\
				srcs/ft_lstfind.c			\
				srcs/ft_lstcontentfind.c	\
				srcs/ft_lstpushback.c		\
				srcs/ft_lstlast.c			\
				srcs/ft_lstfree.c			\
				srcs/ft_lstremove.c
OBJ			=	$(SRC:.c=.o)
SRC_FOLDER	=	./srcs
INCLUDES	=	./includes
FLAGS		=	-Wall -Wextra -Werror
NORM_FILES	=	$(shell find . -name "*.c" -o -name "*.h")

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	@ar rcs $(NAME) $(OBJ)

.c.o: $(SRC)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	@gcc -c $< -o $@ -I $(INCLUDES) $(FLAGS)

norm:
	@printf "\033[32mNorminette:\033[0m "
	@if ! norminette $(NORM_FILES) | grep -sB1 -E "Error|Warning";then echo "\033[0mEvery file is following the norm";fi

clean:
	@printf "\033[32m  Cleaning: \033[0m"
	@find . -name "*.o" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(OBJ)

fclean: clean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "libft.a" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(NAME)

re: fclean all
