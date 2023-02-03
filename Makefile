NAME = pipex

NAME_BONUS = Pipex

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

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

DARKBLUE = \033[1;34m
RED = \033[1;31m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREEN = \033[1;32m
RED_UNDERLINE = \033[4;31m\033[1;31m
END = \033[0m

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)
	@clear
	@sleep 0.1
	@echo	"███╗██████╗ ██╗██████╗ ███████╗██╗  ██╗    ███╗   ███╗ █████╗ ██████╗  █████╗ ██╗  ██╗ █████╗ ███╗   ██╗██╗███╗"
	@sleep 0.1
	@echo	"██╔╝██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ████╗ ████║██╔══██╗██╔══██╗██╔══██╗██║  ██║██╔══██╗████╗  ██║██║╚██║"
	@sleep 0.1
	@echo	"██║ ██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██╔████╔██║███████║██████╔╝███████║███████║███████║██╔██╗ ██║██║ ██║"
	@sleep 0.1
	@echo	"██║ ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██║╚██╔╝██║██╔══██║██╔══██╗██╔══██║██╔══██║██╔══██║██║╚██╗██║██║ ██║"
	@sleep 0.1
	@echo	"███╗██║     ██║██║     ███████╗██╔╝ ██╗    ██║ ╚═╝ ██║██║  ██║██████╔╝██║  ██║██║  ██║██║  ██║██║ ╚████║██║███║"
	@sleep 0.1
	@echo	"╚══╝╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚══╝"
	@sleep 0.1
	@echo   ""
	@echo "                    =================================================="
	@echo "                    || ${CYAN}how to use: ${RED}./pipex infile cmd1 cmd2 outfile ${END}||"
	@echo "                    =================================================="
                                                                                                               
                                           

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BNS_OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(BNS_OBJ) $(LIBFT_OBJ) -o $(NAME)
	@clear
	@sleep 0.1
	@echo	"███╗██████╗ ██╗██████╗ ███████╗██╗  ██╗    ${GREEN}██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗${END}███╗"
	@sleep 0.1
	@echo	"██╔╝██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ${GREEN}██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝${END}╚██║"
	@sleep 0.1
	@echo	"██║ ██████╔╝██║██████╔╝█████╗   ╚███╔╝     ${GREEN}██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗${END} ██║"
	@sleep 0.1
	@echo	"██║ ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ${GREEN}██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║${END} ██║"
	@sleep 0.1
	@echo	"███╗██║     ██║██║     ███████╗██╔╝ ██╗    ${GREEN}██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║${END}███║"
	@sleep 0.1
	@echo	"╚══╝╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ${GREEN}╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝${END}╚══╝"
	@sleep 0.1
	@echo   ""
	@echo "                ==========================================================="
	@echo "                || ${CYAN}how to use: ${RED}./pipex here_doc limiter cmd1 cmd2 outfile${END}||"
	@echo "                ==========================================================="
                                                                                           

clean:
	@rm -f $(OBJ) $(BNS_OBJ) $(LIBFT_OBJ)

fclean: clean
	@echo "${GREEN}cleaning...${END}"
	@sleep 1
	@rm -f $(NAME)
	@echo "${GREEN}DONE √${END}"

re: fclean all

czar: all clean

czarb: bonus clean

.PHONY:all clean fclean re czar bonus
