/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:03:23 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 13:03:23 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		handle_error(
			"Error\nInvalid Arguments!\t try this: ./so_long [map.ber]\n",
			1, (void *)0);
	if (check_path(argv[1]) == 0)
		handle_error(
			"Error\nInvalid file extension! Only .ber files\n",
			1, (void *)0);
}
