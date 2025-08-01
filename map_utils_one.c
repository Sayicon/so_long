/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:01:23 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 14:01:23 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <stdlib.h>

int	check_path(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (!path || i < 5 || path[0] == '.')
		return (0);
	path = ft_strrchr(path, '.');
	if (!path || *(path - 1) == '/' || ft_strlen(path) != 4 || path[0] != '.'
		|| path[1] != 'b' || path[2] != 'e' || path[3] != 'r')
		return (0);
	return (1);
}

void	handle_map(t_game *game, char *path)
{
	char	*map_buffer;
	char	*map_check_result;

	map_buffer = get_map(path);
	if (!map_buffer)
		handle_error("Error\nFailed to read map.\n", 0, (void *)0);
	game->map.this_map = ft_split(map_buffer, '\n');
	if (!game->map.this_map)
		handle_error("Error\nFailed to read map.\n", 3, map_buffer);
	else
		free(map_buffer);
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
	game->c_l_f_img = NULL;
	game->c_l_b_img = NULL;
	game->c_r_f_img = NULL;
	game->c_r_b_img = NULL;
	game->bg_img = NULL;
	game->collec_img = NULL;
	game->exit_img = NULL;
	game->wall_img = NULL;
	game->win = NULL;
	game->mlx = NULL;
	game->player.current_image = NULL;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
}
