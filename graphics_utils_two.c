/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:55:56 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 17:55:56 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	pos_event_handler(t_game *game, int move_flag);
static int	event_handler(int keycode, t_game *game);
static int	player_pos_updater(int key, t_game *game_data);
int			exit_game(t_game *game);

void	game_loop(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS, 1, event_handler, game);
	mlx_hook(game->win, KEY_EXIT, 0, exit_game, game);
	mlx_loop(game->mlx);
}

static int	event_handler(int keycode, t_game *game)
{
	int	move_flag;

	if (keycode == KEY_ESC)
		exit_game(game);
	move_flag = select_player_image(keycode, game);
	if (keycode == KEY_W && game->map.this_map[game->player.pos.y - 1]
		[game->player.pos.x] != '1')
		move_flag += player_pos_updater(keycode, game);
	else if (keycode == KEY_S && game->map.this_map[game->player.pos.y + 1]
		[game->player.pos.x] != '1')
		move_flag += player_pos_updater(keycode, game);
	else if (keycode == KEY_A && game->map.this_map[game->player.pos.y]
		[game->player.pos.x - 1] != '1')
		move_flag += player_pos_updater(keycode, game);
	else if (keycode == KEY_D && game->map.this_map[game->player.pos.y]
		[game->player.pos.x + 1] != '1')
		move_flag += player_pos_updater(keycode, game);
	pos_event_handler(game, move_flag);
	if (move_flag)
		render_game(game, 0);
	return (0);
}

static int	player_pos_updater(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.pos.y--;
	else if (keycode == KEY_S)
		game->player.pos.y++;
	else if (keycode == KEY_A)
		game->player.pos.x--;
	else if (keycode == KEY_D)
		game->player.pos.x++;
	if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
		return (1);
	return (0);
}

static void	pos_event_handler(t_game *game, int move_flag)
{
	t_position	*p_pos;
	t_map		*map;

	map = &(game->map);
	p_pos = &(game->player.pos);
	if (move_flag != 0)
	{
		map->counter.step += 1;
		ft_putnbr_fd(map->counter.step, 1);
		ft_putstr_fd("\n", 1);
	}
	if (map->this_map[p_pos->y][p_pos->x] == COLLECTEBLE)
	{
		map->this_map[p_pos->y][p_pos->x] = 0;
		map->counter.collecteble -= 1;
	}
	if (map->counter.collecteble == 0
		&& map->this_map[p_pos->y][p_pos->x] == EXIT)
		exit_game(game);
}

int	exit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
