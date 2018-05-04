# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 06:09:40 by cboiron           #+#    #+#              #
#    Updated: 2017/05/11 23:23:04 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c image_printing.c init_env.c draw_julia.c draw_mandelbrot.c \
	  choose_fractal.c mouse_key.c draw_burning_ship.c print_info.c \
	  draw_center.c draw_jules.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(OBJ) $(FLAG) libft/libft.a -lmlx -framework OpenGL -framework Appkit

clean :
	rm -rf $(OBJ)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all
