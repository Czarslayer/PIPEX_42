NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c\
	parsing.c\

CC = gcc

OBJ = $(SRC:.c=.o)

all: libft.a $(NAME)

libft.a:
	make -C libft
	cp libft/libft.a .

$(NAME): $(OBJ) libft.a
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

bonus: all

clean:
	@rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	@clear
	@rm -f $(NAME) libft.a

re: fclean all

czar: all clean

.PHONY:all clean fclean re czar bonus
