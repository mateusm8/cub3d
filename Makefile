# Makefile for Cub3d

NAME		= Cub3d

# Directories
MINILIBX	= ./minilibx-linux/libmlx.a
HDR			= include/
SRC_DIR		= src/
OBJ_DIR		= obj/

# Compiler
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(HDR)
RM			= rm -f
MLX_FLAGS	= -lXext -lX11 -lm -lz

# Source files
INIT_SRC	= $(SRC_DIR)init/init_game.c \
			  $(SRC_DIR)init/init_player.c \
			  $(SRC_DIR)init/init_texture.c

INPUT_SRC	= $(SRC_DIR)input/keys.c \
			  $(SRC_DIR)input/movement.c

RENDER_SRC	= $(SRC_DIR)render/draw.c \
			  $(SRC_DIR)render/raycast.c \
			  $(SRC_DIR)render/render.c \
			  $(SRC_DIR)render/texture.c

PARSER_SRC	= $(SRC_DIR)parser/parse.c \
			  $(SRC_DIR)parser/parse_elements.c \
			  $(SRC_DIR)parser/parse_map.c

UTILS_SRC	= $(SRC_DIR)utils/cleanup.c \
			  $(SRC_DIR)utils/errors.c \
			  $(SRC_DIR)utils/math_utils.c

SRCS		= $(INIT_SRC) $(INPUT_SRC) $(RENDER_SRC) $(PARSER_SRC) \
			  $(UTILS_SRC) $(SRC_DIR)main.c

OBJ			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Rules
all:		$(NAME)

$(MINILIBX):
			@make -C minilibx-linux

$(NAME):	$(OBJ) $(MINILIBX)
			@$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
			@echo "Cub3d compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
