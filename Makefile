# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:00:52 by jrouillo          #+#    #+#              #
#    Updated: 2023/02/20 16:28:24 by jrouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### PROGRAM NAME ####################

NAME = so_long

# PATH
SRC_PATH = src/
OBJ_PATH = obj/


###################### SOURCES ######################

SRC = so_long.c \
		init_map.c \
		check_map.c \
		check_map_walls.c \
		check_map_valid_route.c \
		check_map_valid_route_2.c \
		free_map.c \
		keys.c \
		render_image.c \
		window.c \
		utils.c \
		get_next_line.c \
		choose_image.c
SRC2 = $(addprefix $(SRC_PATH), $(SRC))


###################### OBJECTS ######################

OBJ = $(SRC:.c=.o)
OBJ2 = $(addprefix $(OBJ_PATH), $(OBJ))


####################### FLAGS #######################

CCF  = clang $(FLAGS)
FLAGS = -Wall -Werror -Wextra -g


###################### INCLUDE ######################

INC = -I ./includes/ \
		-I ./libft/ \
		-I ./mlx_linux/

HDR = includes/so_long.h \
		mlx_linux/mlx.h \
		mlx_linux/mlx_int.h


####################### LIBFT #######################

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a


######################## MLX ########################

MLX_PATH = mlx_linux/
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L/mlx_linux -lXext -lX11 -lm -lz


############## FONT COLORS AND EFFECTS ##############

_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_CYAN=\033[36m
_BOLD=\033[1m'


####################### RULES #######################

all : $(OBJ_PATH) $(LIBFT) $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	@echo -n "$(_GREY)-${END}"
	@$(CCF) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@echo "$(_GREY)Compiling Libft...${_END}"
	@make -sC $(LIBFT_PATH)
	@echo "$(_GREEN)\n\n✅ Libft compiled\n${_END}"

$(MLX):
	@echo "$(_GREY)Compiling MiniLibX...\n${_END}"
	@make -sC $(MLX_PATH)
	@echo "$(_GREEN)\n✅ MiniLibX compiled\n${_END}"

$(NAME): $(OBJ2)
	@echo "$(_GREY)\nCompiling So_long...${_END}"
	@$(CCF) $(OBJ2) $(LIBFT) $(MLX) $(MLX_FLAGS) $(INC) -o $(NAME)
	@echo "$(_GREEN)\n✅ So_long compiled\n${_END}"
	@echo "$(_GREEN)\n🆗🕺 READY 🕺🆗\n${_END}"

malloc_test: $(OBJ_PATH) $(OBJ2) $(LIBFT) $(MLX) $(NAME)
	$(CCF) -fsanitize=undefined -rdynamic -o $@ ${OBJ2} $(LIBFT) $(INC) -L. -lmallocator

clean:
	@make clean -sC $(LIBFT_PATH)
	@echo "$(_CYAN)\n🌀 Libft cleaned\n${_END}"
	@make clean -sC $(MLX_PATH)
	@echo "$(_CYAN)\n🌀 MiniLibX cleaned\n${_END}"
	@rm -rf $(OBJ_PATH)
	@echo "$(_CYAN)\n🌀 So_long cleaned\n${_END}"
	@echo "$(_CYAN)🚿🛁 ✧ ALL CLEANED ✧ 🛁🚿\n${_END}"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re