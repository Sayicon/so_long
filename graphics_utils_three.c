/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:46 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/20 17:15:10 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_img_two(int keycode, t_game *game, int *move_flag, void **img);
static void	sl_img_three(int keycode, t_game *game, int *move_flag, void **img);
static int	swap_images(void **current_img, void *new_img);

int	select_player_image(int keycode, t_game *game)
{
	void	**img;
	int		move_flag;

	img = &(game->player.current_image);
	move_flag = 0;
	if (keycode == KEY_W)
	{
		if (game->player.current_image == game->c_l_f_img)
			move_flag = swap_images(img, game->c_l_b_img);
		else if (game->player.current_image == game->c_r_f_img)
			move_flag = swap_images(img, game->c_r_b_img);
		if (game->map.this_map
			[game->player.pos.y - 1][game->player.pos.x] == '1')
			move_flag = 0;
	}
	sl_img_two(keycode, game, &move_flag, img);
	sl_img_three(keycode, game, &move_flag, img);
	return (move_flag);
}

static void	sl_img_two(int keycode, t_game *game, int *move_flag, void **img)
{
	if (keycode == KEY_S)
	{
		if (game->player.current_image == game->c_l_b_img)
			*move_flag = swap_images(img, game->c_l_f_img);
		else if (game->player.current_image == game->c_r_b_img)
			*move_flag = swap_images(img, game->c_r_f_img);
		if (game->map.this_map
			[game->player.pos.y + 1][game->player.pos.x] == '1')
			*move_flag = 0;
	}
	else if (keycode == KEY_A)
	{
		if (game->player.current_image == game->c_r_b_img)
			*move_flag = swap_images(img, game->c_l_b_img);
		else if (game->player.current_image == game->c_r_f_img)
			*move_flag = swap_images(img, game->c_l_f_img);
		if (game->map.this_map
			[game->player.pos.y][game->player.pos.x - 1] == '1')
			*move_flag = 0;
	}
}

static void	sl_img_three(int keycode, t_game *game, int *move_flag, void **img)
{
	if (keycode == KEY_D)
	{
		if (game->player.current_image == game->c_l_b_img)
			*move_flag = swap_images(img, game->c_r_b_img);
		else if (game->player.current_image == game->c_l_f_img)
			*move_flag = swap_images(img, game->c_r_f_img);
		if (game->map.this_map
			[game->player.pos.y][game->player.pos.x + 1] == '1')
			*move_flag = 0;
	}
}

static int	swap_images(void **current_img, void *new_img)
{
	if (*current_img != new_img)
		*current_img = new_img;
	else
		return (0);
	return (1);
}
