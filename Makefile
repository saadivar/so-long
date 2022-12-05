SRC = get_next_line_utils.c flood_fill.c get_next_line.c so_long.c split.c printf/ft_printf_functions.c printf/ft_printf.c floode.c data.c checkmap.c hooks.c moves.c floodmoves.c parse.c readcheck.c

OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
all: $(NAME)

$(NAME): $(OBJFILES)
	cc $(CFLAGS) $(OBJFILES) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	rm -rf $(OBJFILES)


fclean: clean
	rm -rf $(NAME)
re:fclean all