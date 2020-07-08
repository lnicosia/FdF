# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/01/31 17:45:20 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MAKEFILE = Makefile

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_RAW = main.c plot_line.c hook_more.c parser.c zoom.c event_utils.c \
	  coord_utils.c init_map.c trace.c increase_z_and_color.c map_movement.c \
	  plot_line_aa.c hook_key_and_mouse.c math.c rotate.c debug_utils.c \
	  fill_poly.c coord_stack.c menu.c put_strings.c background.c \
	  color_pickers.c print_centers.c plot_line_z.c black_white_mode.c \
	  fill_poly_maths.c pre_project.c adapt.c project.c coord_max.c \
	  screen_utils.c init_data.c init_arrays.c logs.c put_buttons.c \
	  put_button_strings.c key_press.c mouse_press.c fcoord_max.c \
	  fill_computing.c

HEADERS = utils.h color.h mlx_keycode.h user_functions.h coord_stack.h \
		  color_pickers.h error.h fill_poly_utils.h buttons.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -g3 -O3 -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		 -I $(LIBFT_DIR)

#MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
MLX = -lmlx -I minilibx/

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all:
	@make -C $(LIBFT_DIR)
	@make $(BIN_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ $(CFLAGS) 

$(BIN_DIR)/$(NAME): $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled '$(NAME)' executable with success!"${RESET}

clean: 
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@make clean -C libft
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] with success!"${RESET}
	@echo ${CYAN}"[INFO] Removed [$(OBJ_DIR)] with success!"${RESET}

fclean: clean
	@rm -Rf fdf
	@rm -Rf fdf_leaks
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

.PHONY: fclean all clean libft
