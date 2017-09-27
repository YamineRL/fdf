# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 11:17:27 by yhaddar           #+#    #+#              #
#    Updated: 2017/09/27 13:55:07 by yhaddar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror -fsanitize=address -I.

SRCS =		main.c \
			errors.c \
			display.c \
			draw.c \
			keyhook.c \
			bonus_colors.c \
			new_points.c \
			get_next_line.c \

OBJS =		$(SRCS:.c=.o)

LIBFT_PATH =	./libft

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAG) $(SRCS) -I./mlx/mlx.h -framework OpenGL -framework Appkit -L./libft -lmlx -lft -o $(NAME) -g
	@echo "fdf built"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
