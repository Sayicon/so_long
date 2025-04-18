#include "so_long.h"
#include <stdlib.h>

int	check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i ++;
	if (i < 5 || !path[0] || path[i - 4] != '.' || path[i - 3] != 'b' || path[i - 2] != 'e' || path[i - 1] != 'r')
		return (0);
	return (1);
}

void	handle_map(t_game *game, char *path)
{
	char *map_check_result;

	game->map.this_map = get_map(path);
	if (!game->map.this_map)
		handle_error("Error\nFailed to read map.\n", 1, NULL);
	map_check_result = map_check(&(game->map));
	if (map_check_result != 0)
		handle_error(map_check_result, 2, &(game->map));
	game->player.pos = get_player_pos(&(game->map));
}

void	free_map(char ***map)
{
	int	i;

	if (!map || !(*map))
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i++;
	}
	free(*map);
	*map = NULL;
}

void	init_map(t_map *map)
{
	map->w = 0;
	map->h = 0;
	map->this_map = NULL;
	map->counter.player = 0;
	map->counter.collecteble = 0;
	map->counter.exit = 0;
	map->counter.step = 0;
}

void	init_game(t_game *game)
{
	init_map(&(game->map));
	game->character_left_front_img = NULL;
	game->character_left_back_img = NULL;
	game->character_right_front_img = NULL;
	game->character_right_back_img = NULL;
	game->background_img = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
	game->wall_img = NULL;
	game->win = NULL;
	game->mlx = NULL;
	game->player.current_image = NULL;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
}