# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:17 by abarriga          #+#    #+#              #
#    Updated: 2023/01/20 12:13:20 by abarriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c fractales.c fractol_utils.c fractol_utils2.c
OBJ = ${SRC:.c=.o}
CC = gcc
RM = rm -f

LIBMLX42 = -lmlx42 -LMLX42
# PARA EL MAC PERSONAL
# LIBGLFW = -lglfw -L /usr/local/Cellar/glfw/3.3.8/lib/
 # PARA EL MAC DE 42
LIBGLFW = -lglfw -L /sgoinfre/goinfre/Perso/abarriga/homebrew/Cellar/glfw/3.3.8/lib
all: ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -IMLX42/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) ${LIBMLX42} ${LIBGLFW} -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	${MAKE} ${NAME}

