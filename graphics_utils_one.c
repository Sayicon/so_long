/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:28:59 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 14:28:59 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	img_width;
	int	img_height;

	game->bg_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/background.xpm", &img_width, &img_height);
	game->c_l_b_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left_back.xpm", &img_width, &img_height);
	game->c_l_f_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left_front.xpm", &img_width, &img_height);
	game->c_r_b_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right_back.xpm", &img_width, &img_height);
	game->c_r_f_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right_front.xpm", &img_width, &img_height);
	game->collec_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &img_width, &img_height);
	if (!game->bg_img || !game->c_l_b_img
		|| !game->c_l_f_img || !game->c_r_b_img
		|| !game->c_r_f_img || !game->collec_img
		|| !game->exit_img || !game->wall_img)
		handle_error("Error\nFailed to load images.\n", 4, game);
	game->player.current_image = game->c_l_f_img;
}

void	render_game(t_game *game, int r_case)
{
	t_position	cursor;

	cursor = (t_position){0, 0};
	while (cursor.y < game->map.h)
	{
		while (cursor.x < game->map.w)
		{
			if (game->map.this_map[cursor.y][cursor.x] == WALL && r_case == 1)
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else if (game->map.this_map[cursor.y][cursor.x] == COLLECTEBLE)
				mlx_put_image_to_window(game->mlx, game->win, game->collec_img,
					cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else if (game->map.this_map[cursor.y][cursor.x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			else if (game->map.this_map[cursor.y][cursor.x] != WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->bg_img,
					cursor.x * PIXEL_SIZE, cursor.y * PIXEL_SIZE);
			cursor.x++;
		}
		cursor = (t_position){0, cursor.y + 1};
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.current_image,
		game->player.pos.x * PIXEL_SIZE, game->player.pos.y * PIXEL_SIZE);
}
