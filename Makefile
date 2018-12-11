# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2018/12/11 15:23:19 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LEAKS = fdf_leaks

SRC = main.c plot_line.c hook_more.c parser.c \
	  coord_utils.c init_map.c trace.c

NO_LEAKS_SRC = hook_key_and_mouse.c

LEAKS_SRC = hook_key_and_mouse_leaks.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o) 

NO_LEAKS_OBJ = $(NO_LEAKS_SRC:.c=.o)

LEAKS_OBJ = $(LEAKS_SRC:.c=.o)

INCLUDES = libft

CFLAGS = -O3 -g -Wall -Wextra -Werror -I $(INCLUDES) -fsanitize=address

LIB = /usr/local/lib -lmlx -framework OpenGL -framework Appkit

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"
BLINK := "\033[5m"

all: libft $(NAME)

leaks: libft $(LEAKS)

libft:
	@make -C libft all

$(NAME): $(OBJ) $(NO_LEAKS_OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(NO_LEAKS_OBJ) -L $(LIB) $(LIBFT) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"

$(LEAKS): $(OBJ) $(LEAKS_OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LEAKS_OBJ) -L $(LIB) $(LIBFT) -o $(LEAKS)
	@echo ${GREEN}"[INFO] Compiled [$(LEAKS)] executable successfully!"

clean: 
	@rm -Rf $(OBJ) $(NO_LEAKS_OBJ) $(LEAKS_OBJ)
	@make clean -C libft
	@echo ${CYAN}"[INFO] Removed [$(OBJ)$(LEAKS_OBJ) $(NO_LEAKS_OBJ)] successfully!"

fclean: clean
	@rm -Rf fdf
	@rm -Rf fdf_leaks
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

.SILENT: $(OBJ) $(LEAKS_OBJ) $(NO_LEAKS_OBJ)
.PHONY: fclean all clean libft
