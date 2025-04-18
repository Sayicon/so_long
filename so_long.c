#include "so_long.h"

void	check_arguments(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arguments(argc, argv);
	init_game(&game);
	handle_map(&game, argv[1]);
	run_game(&game);
	free_game(&game);
	return (0);
}

void	check_arguments(int argc, char *argv[])
{
	if (argc != 2)
		handle_error("Error\nInvalid Arguments!\ttry this: ./so_long [map.ber]\n", 1, (void *)0);
	if (check_path(argv[1]) == 0)
		handle_error("Error\nInvalid map file extension! Only .ber files are allowed.\n", 1, (void *)0);
}
