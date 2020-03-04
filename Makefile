# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 17:27:41 by gsanz-sz          #+#    #+#              #
#    Updated: 2020/03/03 20:53:59 by gsanz-sz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

SRCS_DIR = ./source
SRCS = 

OBJ_DIR = ./objects
OBJ = $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

LIB_DIR = ./Libft
LIB = libft.h

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	gcc ${FLAGS} -c $< -o $@

$(LIBFT):
	$(MAKE) -C ${LIB_DIR}

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
