NAME = so_long

SO_LONG_SRC = so_long.c map_utils_one.c map_utils_two.c map_utils_three.c map_utils_four.c so_long_utils_one.c graphics_utils_one.c graphics_utils_two.c graphics_utils_three.c
SO_LONG_OBJS = $(SO_LONG_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_MAKE = make -s -C $(LIBFT_DIR)/
LIBFT = $(LIBFT_DIR)/libft.a

GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_SRC = $(GET_NEXT_LINE_DIR)/get_next_line_bonus.c $(GET_NEXT_LINE_DIR)/get_next_line_utils_bonus.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRC:.c=.o)

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -lXext -lX11 -lm -lz
MLX_MAKE = make -s -C $(MLX_DIR)/
MLX = $(MLX_DIR)/libmlx.a


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(SO_LONG_OBJS) $(GET_NEXT_LINE_OBJS) $(MLX)
		$(CC) $(CFLAGS) -o $(NAME) $(SO_LONG_OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)
		@echo "Compilation complete!"
		@echo "Executable: $(NAME)"

${LIBFT}:
		$(LIBFT_MAKE)
		@echo "Libft compiled!"

$(MLX):
		$(MLX_MAKE)
		@echo "Minilibx compiled!"

all: $(NAME)
		@echo "All dependencies compiled!"

clean:
		rm -f $(SO_LONG_OBJS) $(GET_NEXT_LINE_OBJS)
		$(LIBFT_MAKE) clean
		$(MLX_MAKE) -s clean
		@echo "Cleaned all object files!"

fclean:
		rm -f $(NAME) $(SO_LONG_OBJS) $(GET_NEXT_LINE_OBJS)
		$(LIBFT_MAKE) fclean
		$(MLX_MAKE) -s clean
		@echo "Cleaned all files!"

re: fclean $(NAME)

.PHONY: all clean fclean re