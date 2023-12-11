
NAME = so_long


SRC = 	        src/main.c            \
				src/parse_utils.c     \
				src/parsing.c         \
				src/verif.c           \
				src/move_utils.c      \
				src/key_press.c       \
				src/display_utils.c   \
				src/display.c         \
				src/move.c            \

INC = includes/fdf.h

CC = cc

FLAGS = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
MLX_DIR = mlx


all: $(NAME) clean

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@cp $(MLX_DIR)/libmlx.a .
	$(CC) $(FLAGS) $(OBJ)  libft.a libmlx.a -framework OpenGL -framework Appkit -l z  -o $(NAME)
	@rm libft.a
	@make clean -C $(LIBFT_DIR)
	@make clean
	@rm libmlx.a

%.o: %.c
	$(CC) $(FLAGS) -I $(INC) -Imlx -c $< -o $@

clean:
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
