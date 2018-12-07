# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2018/12/07 14:40:42 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c plot_line.c hook_key_and_mouse.c hook_more.c parser.c coord_utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = libft

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"
BLINK := "\033[5m"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) $(OBJ) -O3 -g -L /usr/local/lib -lmlx -framework OpenGL -framework \
		Appkit libft/libft.a -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"

clean: 
	@rm -Rf $(OBJ)
	@make clean -C libft
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] successfully!"

fclean: clean
	@rm -Rf fdf
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"

re: fclean all

.SILENT: $(OBJ)
.PHONY: fclean all clean
