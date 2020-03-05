# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 13:18:30 by mlaraki           #+#    #+#              #
#    Updated: 2020/03/05 13:18:57 by mlaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT = libft

HEADER = includes

FILES = 	ft_init_clear.c \
			ft_utility.c \
			ft_utility2.c \
			ft_pick_flag.c \
			ft_handle_c.c \
			ft_handle_percent.c \
			ft_handle_s.c \
			ft_handle_p.c \
			ft_handle_d.c \
			ft_handle_d2.c \
			ft_handle_u.c \
			ft_handle_x.c \
			ft_printf.c \
			ft_modifiers_handler.c \
			ft_modifiers_handler2.c \


SRCS = $(addprefix srcs/,$(FILES))

OBJS = $(addprefix objs/,$(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Done printf"

objs/%.o: srcs/%.c $(HEADER)/ft_printf.h
	@mkdir -p objs
	@gcc -Wall -Wextra -Werror -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf objs
	@make clean -C $(LIBFT)
	@echo "Mr Propre is awesome"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re
