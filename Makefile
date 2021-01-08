# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 17:27:41 by gsanz-sz          #+#    #+#              #
#    Updated: 2021/01/08 19:07:06 by gsanz-sz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = source/flags.c \
	   source/ft_handler.c \
	   source/ft_isdigit.c \
	   source/ft_itoa.c \
	   source/ft_itoa_base.c \
	   source/ft_itoa_u.c \
	   source/ft_print_c.c \
	   source/ft_print_d.c \
	   source/ft_print_p.c \
	   source/ft_print_percentage.c \
	   source/ft_print_s.c \
	   source/ft_print_u.c \
	   source/ft_print_width.c \
	   source/ft_print_x.c \
	   source/ft_printf.c \
	   source/ft_putchar.c \
	   source/ft_putlstr.c \
	   source/ft_str_lowcase.c \
	   source/ft_strdup.c \
	   source/ft_strlen.c \

OBJ = flags.o \
	  ft_handler.o \
	  ft_isdigit.o \
	  ft_itoa.o \
	  ft_itoa_base.o \
	  ft_itoa_u.o \
	  ft_print_c.o \
	  ft_print_d.o \
	  ft_print_p.o \
	  ft_print_percentage.o \
	  ft_print_s.o \
	  ft_print_u.o \
	  ft_print_width.o \
	  ft_print_x.o \
	  ft_printf.o \
	  ft_putchar.o \
	  ft_putlstr.o \
	  ft_str_lowcase.o \
	  ft_strdup.o \
	  ft_strlen.o \

all: $(NAME)

$(NAME): $(OBJ) 

$(OBJ): $(SRCS)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
