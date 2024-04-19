NAME = so_long

SCRS = src/main.c \
       src/map_copy.c \
	   src/map_file.c \
	   src/struct_map.c \
	   src/errors.c \
	   src/valid_map_char.c \
	   src/valid_wall.c \
	   src/valid_playable.c \
	   src/file_image.c \
	   src/image_window.c

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a

MINILIBX = libs/minilibx/libmlx.a

all: $(NAME)

$(NAME):
	@make -C libs/libft
	@make -C libs/minilibx
	@$(CC) $(FLAGS) $(SCRS) $(LIBFT) $(MINILIBX) -o $(NAME) -Llibs/minilibx -lmlx -lX11 -lXext

clean:
	@make clean -C libs/libft
	@make clean -C libs/minilibx

fclean: clean
	@make fclean -C libs/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re