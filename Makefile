NAME = so_long

SCRS = src/main.c src/validate_part_1.c src/validate_part_2.c

CC = cc

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