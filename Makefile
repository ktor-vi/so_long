
NAME = so_long


SRC = 	src/main.c            \
				src/parse_utils.c     \
				src/parsing.c         \
				src/verif.c         \
				src/move_utils.c         \

INC = includes/fdf.h

CC = cc

FLAGS = -g -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	$(CC) $(FLAGS) $(OBJ)  libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
	@rm libft.a

%.o: %.c
	$(CC) $(FLAGS) -I $(INC) -Imlx -c $< -o $@

clean:
	@make fclean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
