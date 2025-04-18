#include "so_long.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static int	event_handler(int keycode, t_game *game);
static int	player_pos_updater(int key, t_game *game_data);
static int	swap_images(void **current_img, void *new_img);
static int	select_player_image(int keycode, t_game *game);
void		pos_event_handler(t_game *game,int move_flag);
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
	if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_W)
		return (1);
	return (0);
}

static int	select_player_image(int keycode, t_game *game)
{
	void	**img;
	int		move_flag;

	img = &(game->player.current_image);
	move_flag = 0;
	if (keycode == KEY_W)
	{
		if(game->player.current_image == game->character_left_front_img)
			move_flag = swap_images(img, game->character_left_back_img);
		else if (game->player.current_image == game->character_right_front_img)
			move_flag = swap_images(img, game->character_right_back_img);
		if (game->map.this_map[game->player.pos.y - 1][game->player.pos.x] != '1')
			move_flag = 0;
	}
	else if (keycode == KEY_S)
	{
		if(game->player.current_image == game->character_left_back_img)
			move_flag = swap_images(img, game->character_left_front_img);
		else if (game->player.current_image == game->character_right_back_img)
			move_flag = swap_images(img, game->character_right_front_img);
		if (game->map.this_map[game->player.pos.y + 1][game->player.pos.x] != '1')
			move_flag = 0;
	}
	else if (keycode == KEY_A)
	{
		if (game->player.current_image == game->character_right_back_img)
			move_flag = swap_images(img, game->character_left_back_img);
		else if (game->player.current_image == game->character_right_front_img)
			move_flag = swap_images(img, game->character_left_front_img);
		if (game->map.this_map[game->player.pos.y][game->player.pos.x - 1] != '1')
			move_flag = 0;
	}
	else if (keycode == KEY_D)
	{
		if (game->player.current_image == game->character_left_back_img)
			move_flag = swap_images(img, game->character_right_back_img);
		else if (game->player.current_image == game->character_left_front_img)
			move_flag = swap_images(img, game->character_right_front_img);
		if (game->map.this_map[game->player.pos.y][game->player.pos.x + 1] != '1')
			move_flag = 0;
	}
	return (move_flag);
}

static int	swap_images(void **current_img, void *new_img)
{
	if (*current_img != new_img)
		*current_img = new_img;
	else
		return (0);
	return (1);
}

void	pos_event_handler(t_game *game,int move_flag)
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
	if (map->counter.collecteble == 0 && map->this_map[p_pos->y][p_pos->x] == EXIT)
		exit_game(game);
}

int	exit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
