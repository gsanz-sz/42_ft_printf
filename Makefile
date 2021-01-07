# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 17:27:41 by gsanz-sz          #+#    #+#              #
#    Updated: 2021/01/07 13:47:45 by gsanz-sz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = ./source
SRCS = $(SRCS_DIR)/flags.c \
	   $(SRCS_DIR)/ft_handler.c \
	   $(SRCS_DIR)/ft_isdigit.c \
	   $(SRCS_DIR)/ft_itoa.c \
	   $(SRCS_DIR)/ft_itoa_base.c \
	   $(SRCS_DIR)/ft_itoa_u.c \
	   $(SRCS_DIR)/ft_print_c.c \
	   $(SRCS_DIR)/ft_print_d.c \
	   $(SRCS_DIR)/ft_print_p.c \
	   $(SRCS_DIR)/ft_print_percentage.c \
	   $(SRCS_DIR)/ft_print_s.c \
	   $(SRCS_DIR)/ft_print_u.c \
	   $(SRCS_DIR)/ft_print_width.c \
	   $(SRCS_DIR)/ft_print_x.c \
	   $(SRCS_DIR)/ft_printf.c \
	   $(SRCS_DIR)/ft_putchar.c \
	   $(SRCS_DIR)/ft_putlstr.c \
	   $(SRCS_DIR)/ft_str_lowcase.c \
	   $(SRCS_DIR)/ft_strdup.c \
	   $(SRCS_DIR)/ft_strlen.c \

OBJ = $(patsubst $(SRCS_DIR)/%.c, %.o, $(SRCS))

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJ)
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

%.o: $(SRCS_DIR)/%.c
	gcc ${FLAGS} -c $< -o $@ -I $(SRCS_DIR)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
