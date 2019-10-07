# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kblack <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 17:05:07 by kblack            #+#    #+#              #
#    Updated: 2019/05/13 04:04:11 by kblack           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fract_ol

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
FRAMEWORKS	= -framework OpenGL -framework AppKit

SRC		=	main.c \
			helper_fdf_functions.c \
			draw_to_image.c \
			rotation.c \
			matrix.c \
			key_movements.c \
			execute_fdf.c 

INC_FT	=	-I includes/libft
LINK_FT	=	-L includes/libft -lft
FT		=	$(INC_FT) $(LINK_FT)

INC_PT	=	-I includes/ft_printf
LINK_PT	=	-L includes/ft_printf -lftprintf
PT 		=	$(INC_PT) $(LINK_PT)

INC_MLX	=	-I minilibx
LINK_MLX	=	-L minilibx -lmlx
MLX 	=	$(INC_MLX) $(LINK_MLX)

OFL = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFL)
	make -C includes/libft
	make -C includes/ft_printf
	make -C minilibx
	@ echo "Creating $(NAME)"
	@ $(CC) -o $@ $(CFLAGS) $(FT) $(PT) $(MLX) $(OFL) -I . $(FRAMEWORKS)

$(OFL): $(SRC)
	@$(CC) $(CFLAGS) $(INC_FT) $(INC_PT) $(INC_MLX) -I . -c $(SRC)
clean:
	rm -rf $(OFL)
	make -C includes/libft clean
	make -C includes/ft_printf clean
	make -C minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C includes/libft fclean
	make -C includes/ft_printf fclean
	# make -C minilibx fclean

re: fclean all
	make -C includes/libft re
	make -C includes/ft_printf re
	make -C minilibx re
