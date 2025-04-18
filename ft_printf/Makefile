NAME = libftprintf.a
FT_PRINTF = ./ft_printf

SRCS_PRINTF = ft_hxdigit_count.c ft_printf.c ft_put_un_nbr.c ft_putaddress.c \
				ft_putchar.c ft_putnbr.c ft_putstr.c ft_putx_low.c ft_putx_up.c
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ------------  RULES  ------------------------------------------------------- #
.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_PRINTF)
			@$(AR) $(NAME) $(OBJS_PRINTF)

%.o: $(FT_PRINTF)/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS_PRINTF)

fclean:	clean
			@$(RM) $(NAME)

re : fclean all