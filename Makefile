# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2018/12/17 15:31:33 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_RAW = main.c plot_line.c hook_more.c parser.c zoom.c event_utils.c \
	  coord_utils.c init_map.c trace.c z_increase.c map_movement.c \
	  plot_line_aa.c hook_key_and_mouse.c

HEADERS = utils.h color.h mlx_keycode.h user_functions.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS = -O3 -g3 -Wall -Wextra -Werror -fsanitize=address -I $(INCLUDES_DIR) \
		 -I $(LIBFT_DIR)

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"
BLINK := "\033[5m"

all:
	@make -C $(LIBFT_DIR)
	@make $(BIN_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable with success!"${RESET}

clean: 
	@rm -Rf $(OBJ)
	@make clean -C libft
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] with success!"${RESET}

fclean: clean
	@rm -Rf fdf
	@rm -Rf fdf_leaks
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

//.SILENT: $(OBJ)
.PHONY: fclean all clean libft
