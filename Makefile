NAME = pipex

NAME_BONUS = Pipex

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c\
	parsing.c\
	parsing_utils.c\

BNS_SRC = pipex_bonus.c\
	parsing_bonus.c\
	get_next_line.c\
	get_next_line_utils.c\
	bonus_utils.c\
	parsing_utils.c\

CC = gcc

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

all: libft.a $(NAME)

libft.a:
	make -C libft
	cp libft/libft.a .

$(NAME): $(OBJ) libft.a
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

bonus: libft.a $(NAME_BONUS)

$(NAME_BONUS): $(BNS_OBJ)
	$(CC) $(CFLAGS) $(BNS_OBJ) libft.a -o $(NAME) 

clean:
	@rm -f $(OBJ) $(BNS_OBJ)
	make -C libft fclean

fclean: clean
	@clear
	@rm -f $(NAME) libft.a $(NAME_BONUS)

re: fclean all

czar: all clean

.PHONY:all clean fclean re czar bonus
