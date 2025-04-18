#include "so_long.h"
#include "minilibx-linux/mlx.h"

static void	load_images(t_game *game);
void		render_game(t_game *game, int r_case);

void	run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error("Error\nFailed to initialize mlx.\n", 4, game);
	game->win = mlx_new_window(game->mlx, game->map.w * PIXEL_SIZE,
			game->map.h * PIXEL_SIZE, "so_long");
	if (!game->win)
		handle_error("Error\nFailed to create window.\n", 4, game);
	load_images(game);
	render_game(game, 1);
	game_loop(game);
}

static void	load_images(t_game *game)
{
	int img_width;
	int img_height;

	game->background_img = mlx_xpm_file_to_image(game->mlx, "./images/background.xpm", &img_width, &img_height);
	game->character_left_back_img = mlx_xpm_file_to_image(game->mlx, "./images/character_left_back.xpm", &img_width, &img_height);
	game->character_left_front_img = mlx_xpm_file_to_image(game->mlx, "./images/character_left_front.xpm", &img_width, &img_height);
	game->character_right_back_img = mlx_xpm_file_to_image(game->mlx, "./images/character_right_back.xpm", &img_width, &img_height);
	game->character_right_front_img = mlx_xpm_file_to_image(game->mlx, "./images/character_right_front.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "./images/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm", &img_width, &img_height);
	if (!game->background_img || !game->character_left_back_img || 
		!game->character_left_front_img || !game->character_right_back_img || 
		!game->character_right_front_img || !game->collectible_img || !game->exit_img || !game->wall_img)
		handle_error("Error\nFailed to load images.\n", 4, game);
	game->player.current_image = game->character_left_front_img;
}

void	render_game(t_game *game, int r_case)
{
	t_position	cursor;

	cursor = (t_position){0, 0};
	while (cursor.y < game->map.h)
	{
		cursor.x = 0;
		while (cursor.x < game->map.w)
		{
			if (game->map.this_map[cursor.y][cursor.x] == WALL && r_case == 1)
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else if (game->map.this_map[cursor.y][cursor.x] == COLLECTEBLE)
				mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else if (game->map.this_map[cursor.y][cursor.x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else
			{
				if (game->map.this_map[cursor.y][cursor.x] != WALL)
					mlx_put_image_to_window(game->mlx, game->win, game->background_img, cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			}
			cursor.x++;
		}
		cursor.y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.current_image, game->player.pos.x * PIXEL_SIZE, game->player.pos.y * PIXEL_SIZE);
}
