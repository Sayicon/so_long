#include "so_long.h"
#include "libft/libft.h"

static char	**clone_map(t_map *map)
{
	int		i;
	char	**cloned_map;

	cloned_map = (char **)ft_calloc(map->h + 1, sizeof(char *));
	if (!cloned_map)
	{
		ft_putstr_fd("Error\nAllocation faild!\n", 2);
		return (0);
	}
	i = 0;
	while (map->this_map[i])
	{
		cloned_map[i] = ft_strdup(map->this_map[i]);
		if (!cloned_map[i])
		{
			free_map(&cloned_map);
			ft_putstr_fd("Error\nAllocation faild!\n", 2);
			return (0);
		}
		i++;
	}
	map->this_map[i] = (void *)0;
	return (cloned_map);
}

static void	ff_recursive(t_map *cloned_map, t_position player_pos, int map_h, int map_w)
{
	if (player_pos.x < 0 || player_pos.x >= map_w || player_pos.y < 0 || player_pos.y >= map_h)
		return ;
	if (cloned_map->this_map[player_pos.y][player_pos.x] == WALL)
		return ;
	if (cloned_map->this_map[player_pos.y][player_pos.x] == COLLECTEBLE)
		cloned_map->counter.collecteble ++;
	else if (cloned_map->this_map[player_pos.y][player_pos.x] == EXIT)
		cloned_map->counter.exit ++;
	cloned_map->this_map[player_pos.y][player_pos.x] = WALL;
	ff_recursive(cloned_map, (t_position){player_pos.x + 1, player_pos.y}, map_h, map_w);
	ff_recursive(cloned_map, (t_position){player_pos.x - 1, player_pos.y}, map_h, map_w);
	ff_recursive(cloned_map, (t_position){player_pos.x, player_pos.y + 1}, map_h, map_w);
	ff_recursive(cloned_map, (t_position){player_pos.x, player_pos.y - 1}, map_h, map_w);
}

static int	check_ff_counts(t_count *map_count, t_count *cloned_count)
{
	if (map_count->collecteble != cloned_count->collecteble || 
		map_count->exit != cloned_count->exit)
		return (1);
	return (0);
}

int	check_flood_fill(t_map *map, t_position player_pos)
{
	t_map	cloned_map;

	init_map(&cloned_map);
	cloned_map.h = map->h;
	cloned_map.w = map->w;
	cloned_map.this_map = clone_map(map);
	if (!cloned_map.this_map)
		return (0);
	ff_recursive(&cloned_map, (t_position){player_pos.x, player_pos.y}, map->h, map->w);
	if (check_ff_counts(&(map->counter), &(cloned_map.counter)))
	{
		ft_putstr_fd("Error\nCollectible items or exit on the map cannot be reached at startup. undefined map.\n", 2);
		free_map(&(cloned_map.this_map));
		return (0);
	}
	free_map(&(cloned_map.this_map));
	return (1);
}