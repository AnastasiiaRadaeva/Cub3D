# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 10:40:54 by kbatwoma          #+#    #+#              #
#    Updated: 2020/06/22 09:52:41 by kbatwoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c	ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_strmapi.c ft_strncmp.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
get_next_line.c ft_free.c
OBJECTS = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJECTS = $(OBJECTS) $(BONUS:.c=.o)

all:$(NAME)

%.o: %.c libft.h
	@$(CC) $(FLAGS) -c $<

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

bonus: $(BONUS_OBJECTS)
	@ar rc $(NAME) $(BONUS_OBJECTS)
	@ranlib $(NAME)
	touch bonus

so: 
	$ gcc -Wall -Wextra -Werror -fPIC -c $(SRC) $(BONUS) -I .
	$ gcc -shared -o libft.so *.o 

clean:
	@rm -f $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re