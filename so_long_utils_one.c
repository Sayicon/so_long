/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:08:50 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 13:08:50 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_position	get_player_pos(t_map *map)
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
	if (game->c_l_f_img)
		mlx_destroy_image(game->mlx, game->c_l_f_img);
	if (game->c_l_b_img)
		mlx_destroy_image(game->mlx, game->c_l_b_img);
	if (game->c_r_f_img)
		mlx_destroy_image(game->mlx, game->c_r_f_img);
	if (game->c_r_b_img)
		mlx_destroy_image(game->mlx, game->c_r_b_img);
	if (game->bg_img)
		mlx_destroy_image(game->mlx, game->bg_img);
	if (game->collec_img)
		mlx_destroy_image(game->mlx, game->collec_img);
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
	if (game->c_l_b_img)
		game->c_l_b_img = NULL;
	if (game->c_l_f_img)
		game->c_l_f_img = NULL;
	if (game->c_r_b_img)
		game->c_r_b_img = NULL;
	if (game->c_r_f_img)
		game->c_r_f_img = NULL;
	if (game->bg_img)
		game->bg_img = NULL;
	if (game->collec_img)
		game->collec_img = NULL;
	if (game->exit_img)
		game->exit_img = NULL;
	if (game->wall_img)
		game->wall_img = NULL;
	if (game->mlx)
		game->mlx = NULL;
	if (game->win)
		game->win = NULL;
}
