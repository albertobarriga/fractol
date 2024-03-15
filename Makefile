# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:17 by abarriga          #+#    #+#              #
#    Updated: 2024/03/14 14:02:25 by abarriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c fractales.c fractol_utils.c fractol_utils2.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS			=	-Wall -Werror -Wextra

ifeq ($(shell uname), Darwin)
	LIBM = MLX42/libmlx42.a	
else
	LIBM = MLX42/libmlx42.a -ldl
endif

RM = rm -f

GLFW = -I include -lglfw -L /Users/abarriga/.brew/Cellar/glfw/3.4/lib
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

docker:
	docker-compose -f ./docker-compose.yml up

.PHONY: all lib clean fclean re
