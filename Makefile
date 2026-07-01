# Makefile for Cub3d

# Standard

NAME					= Cub3d

# Directories
MINILIBX				= ./minilibx-linux/libmlx.a
HDR						= include/
SRC_DIR					= src/
OBJ_DIR					= obj/

# Compiler and CFlags

CC 						= cc
CFLAGS				= -Wall -Werror -Wextra -I$(HDR) -Iinclude
RM					= rm -f
MLX_FLAGS			= -lXext -lX11 -lm -lz

# source files 

INIT_DIR			=	$(SRC_DIR)init/init_game.c \
						$(SRC_DIR)init/init_player.c \
						$(SRC_DIR)init/init_texture.c

INPUT_DIR			=	$(SRC_DIR)input/keys.c \
						$(SRC_DIR)input/movement.c

RENDER_DIR			=	$(SRC_DIR)render/draw.c \
						$(SRC_DIR)render/raycast.c \
						$(SRC_DIR)render/render.c \
						$(SRC_DIR)render/texture.c 

UTILS_DIR			=	$(SRC_DIR)utils/cleanup.c \
						$(SRC_DIR)utils/errors.c \
						$(SRC_DIR)utils/math_utils.c

MAIN_DIR			=	$(SRC_DIR)main.c 

# Concatenate all source files
SRCS 				= $(INIT_DIR) $(INPUT_DIR) $(RENDER_DIR) $(UTILS_DIR) $(MAIN_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

all: 				$(NAME)

$(MINILIBX):		
					@make -C minilibx-linux


$(NAME): 			$(OBJ) $(MINILIBX)
					@$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
					@echo "Cub3d compiled"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(MINILIBX)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re