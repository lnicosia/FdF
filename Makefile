# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2018/12/10 11:05:13 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c plot_line.c hook_key_and_mouse.c hook_more.c parser.c \
	  coord_utils.c init_map.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

INCLUDES = libft

CFLAGS = -O3 -g -Wall -Wextra -Werror -I $(INCLUDES)

LIB = /usr/local/lib -lmlx -framework OpenGL -framework Appkit

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"
BLINK := "\033[5m"

all: libft $(NAME)

libft:
	@make -C libft all
	
$(NAME): $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) -L $(LIB) $(LIBFT) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"

clean: 
	@rm -Rf $(OBJ)
	@make clean -C libft
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] successfully!"

fclean: clean
	@rm -Rf fdf
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

.SILENT: $(OBJ)
.PHONY: fclean all clean libft
