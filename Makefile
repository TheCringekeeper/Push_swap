NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CCFLAG		= -g -Wall -Wextra -Werror

RM			= rm
RMFLAG		= -rf

SMAKE		= make --no-print-directory

SRC			= src/quicksort.c src/error.c src/main.c src/stack_utils.c src/sorting1.c src/sorting2.c src/median.c src/cost.c src/ops_cost.c src/do_ops.c src/parsing.c src/ops.c src/ops_rr.c src/ops_rrr.c src/free.c
OBJ			= $(SRC:c=o)

BSRC		= bonus_src/error_bonus.c bonus_src/main_bonus.c bonus_src/stack_utils_bonus.c bonus_src/parsing_bonus.c bonus_src/ops_bonus.c bonus_src/ops_rr_bonus.c bonus_src/ops_rrr_bonus.c bonus_src/free_bonus.c bonus_src/checker_bonus.c
BOBJ		= $(BSRC:c=o)

LIB			= libft/libft

all			: $(NAME)

$(NAME)		: $(OBJ) Makefile
			@$(SMAKE) -C libft/
			@$(CC) $(CCFLAG) -o $(NAME) $(OBJ) $(LIB)
			@echo "\033[1;35m======= push_swap has been created =======\033[0m"

%.o			: %.c
			@$(CC) $(CCFLAG) -c $< -o $@

clean		:
			@$(SMAKE) -C libft/ clean
			@$(RM) $(RMFLAG) $(OBJ) $(BOBJ)
			@echo "\033[1;36m======= push_swap object files have been removed =======\033[0m"

fclean		:
			@$(SMAKE) -C libft/ fclean
			@$(RM) $(RMFLAG) $(OBJ) $(BOBJ)
			@echo "\033[1;36m======= push_swap object files have been removed =======\033[0m"
			@$(RM) $(RMFLAG) $(NAME) $(BONUS_NAME)
			@echo "\033[1;36m======= push_swap has been removed =======\033[0m"

re			: fclean all

bonus		: $(BOBJ) Makefile
			@$(SMAKE) -C libft/
			@$(CC) $(CCFLAG) -o $(BONUS_NAME) $(BOBJ) $(LIB)
			@echo "\033[1;35m======= bonus has been created =======\033[0m"

re_bonus	: fclean bonus

.PHONY		: all clean fclean re bonus bonusre
