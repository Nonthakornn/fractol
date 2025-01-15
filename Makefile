NAME			:= fractol

# Directories
HDR_DIR			:= include
LIB_DIR			:= lib
SRC_DIR			:= src
OBJ_DIR			:= obj

# Libft
LIBFT_DIR		:= libft
LIBFT			:= ${LIBFT_DIR}/libft.a

# MLX42
MLX_DIR			:= MLX42
MLX				:= ${MLX_DIR}/build/libmlx42.a

# for linux
#MLX_FLAGS	:= -L ${MLX_DIR}/build -lmlx42 -lglfw -lm

#for mac
MLX_FLAGS	:= -L ${MLX_DIR}/build -lmlx42 -lglfw -lm -framework Cocoa -framework OpenGL -framework IOKit

# Compiler flags
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra
INCL			:= -I ${HDR_DIR}/ -I ${LIBFT_DIR}/include/ -I ${MLX_DIR}/include/MLX42/

# Includes
HDR_FILES :=	fractol.h 

# Files
SRC_FILES :=	main.c 

SRC				:= ${addprefix ${SRC_DIR}/, ${SRC_FILES}}
OBJ				:= ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
HDR				:= ${addprefix ${HDR_DIR}/, ${HDR_FILES}}

# Colors
GREEN			:= \033[32;1m
BLUE 			:= \033[34m
RED				:= \033[31;1m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(INCL) -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(LIBFT):
	@ make -C $(LIBFT_DIR)

$(MLX):
	@ cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@ make -C $(MLX_DIR)/build -j4

clean:
	@ echo "$(GREEN)Cleaning..."
	@ make clean -C $(LIBFT_DIR)
	@ rm -rf $(MLX_DIR)/build
	@ rm -rf ${OBJ_DIR}

fclean: clean
	@ echo "$(RED)Fully cleaning LIBFT..."
	@ make fclean -C $(LIBFT_DIR)

	@ echo "$(RED)Fully cleaning MLX42..."
	@ rm -rf $(MLX_DIR)/build

	@ echo "$(RED)Fully cleaning Fractol"
	@ rm -rf ${NAME}

re: fclean $(NAME)

.PHONY: all clean fclean re 