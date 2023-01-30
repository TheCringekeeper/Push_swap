NAME	= push_swap

CC		= cc
CCFLAG	= -g -Wall -Wextra -Werror

RM		= rm
RMFLAG	= -rf

SMAKE	= make --no-print-directory

SRC		= src/quicksort.c src/error.c src/main.c src/stack_utils.c src/sorting1.c src/sorting2.c src/parsing.c src/ops.c src/ops_rr.c src/ops_rrr.c src/utils.c src/free.c
OBJ		= $(SRC:c=o)

BSRC	= bonus_src/
BOBJ	= $(BSRC:c=o)

LIB		= libft/libft

all		: $(NAME)

$(NAME)	: $(OBJ) Makefile
		@$(SMAKE) -C libft/
		@$(CC) $(CCFLAG) -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[1;35m======= push_swap has been created =======\033[0m"

%.o		: %.c
		@$(CC) $(CCFLAG) -c $< -o $@

clean	:
		@$(SMAKE) -C libft/ clean
		@$(RM) $(RMFLAG) $(OBJ) $(BOBJ)
		@echo "\033[1;36m======= push_swap object files have been removed =======\033[0m"

fclean	:
		@$(SMAKE) -C libft/ fclean
		@$(RM) $(RMFLAG) $(OBJ) $(BOBJ)
		@echo "\033[1;36m======= push_swap object files have been removed =======\033[0m"
		@$(RM) $(RMFLAG) $(NAME)
		@echo "\033[1;36m======= push_swap has been removed =======\033[0m"

re		: fclean all

bonus	: $(BOBJ)
		@$(SMAKE) -C libft/
		@$(CC) $(CCFLAG) -o $(NAME) $(BOBJ)
		@echo "\033[1;35m======= bonus has been created =======\033[0m"

rebonus	: fclean bonus

.PHONY	: all clean fclean re bonus bonusre
