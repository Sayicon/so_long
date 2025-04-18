#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	free_game_pt_two(t_game *game);
static void	clear_game(t_game *game);

void	handle_error(char *message, int error_type, void *ptr)
{
	if (message)
		ft_putstr_fd(message, 2);
	if (error_type == 2 && ptr)
		free_map(&(((t_map *)ptr)->this_map));
	else if (error_type == 3 && ptr)
		free((char *)ptr);
	else if (error_type == 4 && ptr)
		free_game((t_game *)ptr);
	exit(EXIT_FAILURE);
}

t_position get_player_pos(t_map *map)
{
	int			i;
	int			j;
	char		**arr_map;
	t_position	player_pos;

	i = 0;
	arr_map = map->this_map;
	player_pos.x = 0;
	player_pos.y = 0;
	while (arr_map[i])
	{
		j = 0;
		while (arr_map[i][j])
		{
			if (arr_map[i][j] == PLAYER)
			{
				player_pos.x = j;
				player_pos.y = i;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

void	free_game(t_game *game)
{
	if (game->map.this_map)
		free_map(&(game->map.this_map));
	if (game->character_left_front_img)
		mlx_destroy_image(game->mlx, game->character_left_front_img);
	if (game->character_left_back_img)
		mlx_destroy_image(game->mlx, game->character_left_back_img);
	if (game->character_right_front_img)
		mlx_destroy_image(game->mlx, game->character_right_front_img);
	if (game->character_right_back_img)
		mlx_destroy_image(game->mlx, game->character_right_back_img);
	if (game->background_img)
		mlx_destroy_image(game->mlx, game->background_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_game_pt_two(game);
	clear_game(game);
}

static void	free_game_pt_two(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		if (game->mlx)
		free(game->mlx);
	}
}

static void	clear_game(t_game *game)
{
	if (game->character_left_back_img)
		game->character_left_back_img = NULL;
	if (game->character_left_front_img)
		game->character_left_front_img = NULL;
	if (game->character_right_back_img)
		game->character_right_back_img = NULL;
	if (game->character_right_front_img)
		game->character_right_front_img = NULL;
	if (game->background_img)
		game->background_img = NULL;
	if (game->collectible_img)
		game->collectible_img = NULL;
	if (game->exit_img)
		game->exit_img = NULL;
	if (game->wall_img)
		game->wall_img = NULL;
	if (game->mlx)
		game->mlx = NULL;
	if (game->win)
		game->win = NULL;
}
