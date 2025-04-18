CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = $(filter-out %_bonus.c main_test.c, $(wildcard *.c))
BONUS_SRCS = $(wildcard *_bonus.c)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) main_test.c -o program
	@echo Derleme Tamamlandı

.PHONY : all clean fclean re bonus test info

info:
	@echo
	@echo "	 [info | all | bonus | clean | fclean | re | test]"
	@echo
	@echo "		info: displays informations"
	@echo "		all: compile the library"
	@echo "		bonus: compile the library with bonus"
	@echo "		clean: remove object files"
	@echo "		fclean: remove object files and archive library"
	@echo "		re: fclean and all"
	@echo "		test: create the test program"