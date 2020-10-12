# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 11:12:01 by user42            #+#    #+#              #
#    Updated: 2020/10/05 15:10:30 by mlacheny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./srcs/

OBJS = $(SRCS:.c=.o)

SRCS		= \
						srcs/ft_print_char.c \
						srcs/ft_printf.c \
						srcs/ft_printf_utils.c \
						srcs/ft_print_ints.c \
						srcs/ft_print_ints_utils.c \
						srcs/ft_print_ints_utils2.c \
						srcs/ft_print_pointer.c \
						srcs/ft_print_string.c \


INCLUDES = -I./include

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ all
	ar rcs $(NAME) $^ libft/*.o

$(OBJS) : $(HEADERS)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@ 

clean:
			rm -f $(OBJS)
			@make -C libft/ clean

fclean: clean
			rm -f  $(NAME)
			@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus lib
