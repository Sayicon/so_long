#include "so_long.h"
#include "libft/libft.h"

static int	is_rectangle_and_valid_chars(t_map *map);
static int	walls_check(t_map *map);
static int	count_objects(t_map *map);

char	*map_check(t_map *map)
{
	if (is_rectangle_and_valid_chars(map) == 0)
		return ("Error\nmap is not rectangular shape or contains invalid characters.\n");
	if (walls_check(map) == 0)
		return ("Error\nmap is not surrounded by walls.\n");
	if (map->w < 4 || map->h < 4 || map->w == map->h)
		return ("Error\nmap is too small or square.\n");
	if (count_objects(map) == 0)
		return ("Error\nmap must contain 1 player, 1 exit and at least 1 collectable.\n");
	if (check_flood_fill(map, get_player_pos(map)) == 0)
		return ("");
	return (0);
}

static int	is_rectangle_and_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->h = 0;
	map->w = (int)ft_strlen(map->this_map[0]);
	while (map->this_map[i])
	{
		if ((int)ft_strlen(map->this_map[i]) != map->w)
			return (0);
		j = 0;
		while (j < map->w)
		{
			if (map->this_map[i][j] != WALL && map->this_map[i][j] != FLOOR && 
				map->this_map[i][j] != PLAYER && map->this_map[i][j] != COLLECTEBLE && 
				map->this_map[i][j] != EXIT)
				return (0);
			j ++;
		}
		i ++;
	}
	map->h = i;
	return (1);
}

static int	walls_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w)
	{
		if (map->this_map[0][i] != WALL || map->this_map[map->h - 1][i] != WALL)
			return (0);
		i ++;
	}
	i = 0;
	while (i < map->h)
	{
		if (map->this_map[i][0] != WALL || map->this_map[i][map->w - 1] != WALL)
			return (0);
		i ++;
	}
	return (1);
}

static int	count_objects(t_map *map)
{
	int	i;
	int	j;

	map->counter.player = 0;
	map->counter.collecteble = 0;
	map->counter.exit = 0;
	i = 0;
	while (map->this_map[i])
	{
		j = 0;
		while (map->this_map[i][j])
		{
			if (map->this_map[i][j] == PLAYER)
				map->counter.player ++;
			else if (map->this_map[i][j] == COLLECTEBLE)
				map->counter.collecteble ++;
			else if (map->this_map[i][j] == EXIT)
				map->counter.exit ++;
			j ++;
		}
		i ++;
	}
	if (map->counter.player != 1 || map->counter.exit != 1 || map->counter.collecteble <= 0)
		return (0);
	return (1);
}
