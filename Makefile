# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 11:17:27 by yhaddar           #+#    #+#              #
#    Updated: 2017/10/03 16:43:02 by yhaddar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror -fsanitize=address
MLX =	-framework OpenGL -framework Appkit

SRCS =		main.c \
			errors.c \
			display.c \
			draw.c \
			keyhook.c \
			bonus_colors.c \
			new_points.c \
			get_next_line.c \

OBJS =		$(SRCS:.c=.o)

MLX_PATH = ./mlx
LIBFT_PATH = ./libft

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_PATH)
	#make -C $(MLX_PATH)
	$(CC) $(CFLAG) $(SRCS) -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME) -g
	@echo "fdf built"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
	#@make -C $(MLX_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
