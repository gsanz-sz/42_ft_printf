# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 17:27:41 by gsanz-sz          #+#    #+#              #
#    Updated: 2020/03/10 22:05:02 by gsanz-sz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

SRCS_DIR = ./source
SRCS = $(SRCS_DIR)/ft_print_c.c \
	   $(SRCS_DIR)/ft_print_d.c \
	   $(SRCS_DIR)/ft_print_p.c \
	   $(SRCS_DIR)/ft_print_percentage.c \
	   $(SRCS_DIR)/ft_print_s.c \
	   $(SRCS_DIR)/ft_print_u.c \
	   $(SRCS_DIR)/ft_print_x.c \
	   $(SRCS_DIR)/ft_putnbr_base.c \
	   $(SRCS_DIR)/ft_printf.c \

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
	gcc ${FLAGS} -c $< -o $@ -I $(LIB_DIR) -I $(SRCS_DIR)

$(LIBFT):
	$(MAKE) -C ${LIB_DIR}

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus

#gcc3w main.c libftprintf.a Libft/libft.a -I ./Libft -I ./source
