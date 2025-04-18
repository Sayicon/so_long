#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL_SIZE		64

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define COLLECTEBLE	'C'
# define EXIT			'E'

typedef struct position
{
	int		x;
	int		y;
}			t_position;

typedef struct count
{
	int		player;
	int		collecteble;
	int		exit;
	int		step;
}			t_count;


typedef struct map
{
	int				w;
	int				h;
	char			**this_map;
	struct count	counter;
}			t_map;

typedef struct player
{
	void		*current_image;
	t_position	pos;
}				t_player;

typedef struct game
{
	void		*character_left_front_img;
	void		*character_left_back_img;
	void		*character_right_front_img;
	void		*character_right_back_img;
	void		*background_img;
	void		*collectible_img;
	void		*exit_img;
	void		*wall_img;
	t_player	player;
	t_map		map;
	void		*win;
	void		*mlx;
}			t_game;

void		run_game(t_game *game);
void		game_loop(t_game *game);
void		render_game(t_game *game, int r_case);
int			check_path(char *path);
void		init_map(t_map *map);
void		init_game(t_game *game);
void		free_map(char ***map);
void		free_game(t_game *game);
char		**get_map(char *path);
char		*map_check(t_map *map);
int			check_flood_fill(t_map *map, t_position player_pos);
void		handle_map(t_game *game, char *path);
void		handle_error(char *message, int error_type, void *ptr);
t_position	get_player_pos(t_map *map);

#endif