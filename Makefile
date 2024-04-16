NAME = so_long

SCRS = src/main.c src/map_copy.c src/map_file.c src/struct_map.c src/errors.c src/valid_map_char.c src/valid_wall.c src/valid_playable.c

CC = clang -g

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libs/libft
	@$(CC) $(FLAGS) $(SCRS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libs/libft

fclean: clean
	@make fclean -C libs/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re