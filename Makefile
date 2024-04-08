NAME = so_long

SCRS =

OBJS = $(SRC:.c=.o)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libs/libft
	@$(CC) $(FLAGS) $(OBJS) libft/$(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re