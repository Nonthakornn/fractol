NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a
MLX_DIR = MLX42
MLX_LIB = MLX42/build/libmlx42.a
MLXFLAGS = -Iincludes -ldl -lglfw -pthread -lm
IFLAGS = -I$(LIBFT_DIR) -I$(MLX_DIR) 



SRC_PATH = src/
SRC = main.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ_FILES = $(SRCS:.c=.o)

BLUE = \033[34m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			@make -C $(LIBFT_DIR)
			@echo "$(BLUE)libft Success$(RESET)"
			$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) -o $(NAME)
			@echo "$(BLUE)Fractol Success$(RESET)"
			cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4


%.o:		%.c
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)	
			@$(RM) ${OBJ_FILES}
			@$(RM) $(MLX_DIR)/build
			@echo "$(BLUE)Clean Success$(RESET)"

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@$(RM) $(MLX_DIR)/build
			@echo "$(BLUE)FClean Success$(RESET)"

re:			fclean all

.PHONY:		all libft clean fclean re libmlx