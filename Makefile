# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 11:17:27 by yhaddar           #+#    #+#              #
#    Updated: 2017/10/05 17:01:23 by yhaddar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror
MLX =		-lmlx -framework OpenGL -framework Appkit -L$(MLX_PATH)

SRCS =		./src/main.c \
			./src/errors.c \
			./src/display.c \
			./src/draw.c \
			./src/keyhook.c \
			./src/bonus_colors.c \
			./src/new_points.c \
			./src/get_next_line.c \

OBJS =		$(SRCS:.c=.o)

INCL = ./include
MLX_PATH =	./mlx
LIBFT_PATH =./libft
LIBFT = -L./libft -lft

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAG) $(SRCS) $(MLX) $(LIBFT) -I$(INCL) -o $(NAME)
	@echo "fdf built"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
