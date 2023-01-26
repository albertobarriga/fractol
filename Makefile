# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:17 by abarriga          #+#    #+#              #
#    Updated: 2023/01/26 15:17:41 by abarriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c fractales.c fractol_utils.c fractol_utils2.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBM = MLX42/libmlx42.a

GLFW = -I include -lglfw -L /sgoinfre/goinfre/Perso/abarriga/homebrew/Cellar/glfw/3.3.8/lib
all: ${NAME}

$(NAME): $(OBJ) $(LIBM)
	@gcc -o $(NAME) $(OBJ) $(LIBM) $(GLFW)

$(LIBM):
	make -C MLX42

clean: 
	@make clean -C ./MLX42
	# @make -C $(LIBM_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./MLX42
	$(RM) $(NAME)

re: fclean
	${MAKE} ${NAME}

.PHONY: all lib clean fclean re
