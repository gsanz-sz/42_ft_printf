# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 10:57:00 by gsanz-sz          #+#    #+#              #
#    Updated: 2020/02/06 01:20:57 by gsanz-sz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
	   ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	   ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strmapi.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c \
			ft_lstadd_back.c ft_lstsize.c ft_lstiter.c ft_lstmap.c ft_lstlast.c

OBJ = $(subst .c,.o,$(SRCS))

OBJ_BONUS = $(subst .c,.o,$(SRCS_BONUS))

LIB = libft.h
all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(LIB)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ_BONUS)

$(OBJ_BONUS):
	gcc -Wall -Wextra -Werror -c $(SRCS) $(SRCS_BONUS) -I $(LIB)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
