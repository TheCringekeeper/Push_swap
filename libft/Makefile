NAME	= libft

AR		= @ar
ARFLAGS	= crs

CC		= @cc
CCFLAG	= -Wall -Wextra -Werror

RM		= @rm
RMFLAG	= -rf

SRC			= ft_lstnew.c ft_lstclear.c ft_lstmap.c ft_lstlast.c ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c ft_lstsize.c ft_lstadd_back.c ft_strnstr.c ft_strlcat.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c
OBJS		= $(addprefix objs/,$(SRC:.c=.o))

PRINTF		= ft_putunbr_fd.c ft_putptr_fd.c ft_puthexmin_fd.c ft_puthexmaj_fd.c ft_printf.c ft_putnbr1_fd.c
PRINTF_OBJS	= $(addprefix objs/,$(PRINTF:.c=.o))

GNL			= get_next_line.c get_next_line_utils.c
GNL_OBJS	= $(addprefix objs/,$(GNL:.c=.o))

objs/%.o: %.c
		@mkdir -p objs
		$(CC) $(CCFLAG) -c $< -o objs/$(<:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
		@echo "\033[1;35m======= libft has been created =======\033[0m"

clean	:
		$(RM) $(RMFLAG) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS) objs/
		@echo "\033[1;36m======= libft object files have been removed =======\033[0m"

fclean	:
		$(RM) $(RMFLAG) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS) objs/
		@echo "\033[1;36m======= libft object files have been removed =======\033[0m"
		$(RM) $(RMFLAG) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re bonus
