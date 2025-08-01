/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:13:16 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 14:13:16 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	ff_recursive(t_map *c_map, t_position p_pos, int map_h, int map_w)
{
	if (p_pos.x < 0 || p_pos.x >= map_w
		|| p_pos.y < 0 || p_pos.y >= map_h)
		return ;
	if (c_map->this_map[p_pos.y][p_pos.x] == WALL)
		return ;
	if (c_map->this_map[p_pos.y][p_pos.x] == COLLECTEBLE)
		c_map->counter.collecteble ++;
	else if (c_map->this_map[p_pos.y][p_pos.x] == EXIT)
		c_map->counter.exit ++;
	c_map->this_map[p_pos.y][p_pos.x] = WALL;
	ff_recursive(c_map, (t_position){p_pos.x + 1, p_pos.y},
		map_h, map_w);
	ff_recursive(c_map, (t_position){p_pos.x - 1, p_pos.y},
		map_h, map_w);
	ff_recursive(c_map, (t_position){p_pos.x, p_pos.y + 1},
		map_h, map_w);
	ff_recursive(c_map, (t_position){p_pos.x, p_pos.y - 1},
		map_h, map_w);
}

static int	check_ff_counts(t_count *map_count, t_count *cloned_count)
{
	if (map_count->collecteble != cloned_count->collecteble
		|| map_count->exit != cloned_count->exit)
		return (1);
	return (0);
}

int	check_flood_fill(t_map *map, t_position p_pos)
{
	t_map	cloned_map;

	init_map(&cloned_map);
	cloned_map.h = map->h;
	cloned_map.w = map->w;
	cloned_map.this_map = clone_map(map);
	if (!cloned_map.this_map)
		return (0);
	ff_recursive(&cloned_map, (t_position){p_pos.x, p_pos.y},
		map->h, map->w);
	if (check_ff_counts(&(map->counter), &(cloned_map.counter)))
	{
		ft_putstr_fd(
			"Error\nMap elements cannot be reached at startup. undefined map.\n",
			2);
		free_map(&(cloned_map.this_map));
		return (0);
	}
	free_map(&(cloned_map.this_map));
	return (1);
}
