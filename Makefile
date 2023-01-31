NAME = pipex

NAME_BONUS = Pipex

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = pipex.c\
	parsing.c\
	parsing_utils.c\

BNS_SRC = pipex_bonus.c\
	parsing_bonus.c\
	./gnl/get_next_line.c\
	./gnl/get_next_line_utils.c\
	bonus_utils.c\
	parsing_utils.c\

LIBFT_SRC = 	./libft_tools/ft_putstr_fd.c\
	./libft_tools/ft_split.c\
	./libft_tools/ft_strdup.c\
	./libft_tools/ft_strjoin.c\
	./libft_tools/ft_strlen.c\
	./libft_tools/ft_strncmp.c\
	./libft_tools/ft_strnstr.c\


OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BNS_OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(BNS_OBJ) $(LIBFT_OBJ) -o $(NAME) 

clean:
	@rm -f $(OBJ) $(BNS_OBJ) $(LIBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

czar: all clean

czarb: bonus clean

.PHONY:all clean fclean re czar bonus
