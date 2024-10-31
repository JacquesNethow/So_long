/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:09:07 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 22:43:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	verify_argc(argc);
	init_vars(&game);
	read_map(argv[1], &game);
	init_game(&game);
	mlx_hook(game.vars.mlx_win, 12, 1L << 15, render_game, &game);
	mlx_hook(game.vars.mlx_win, 3, 1L << 1, key_press, &game);
	mlx_hook(game.vars.mlx_win, 17, 0L, exit_click, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}

void	init_vars(t_game *game)
{
	game->n_moviment = 0;
	game->map.items = 0;
	game->map.exit = 0;
	game->map.n_player = 0;
}

void	init_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.mlx_win = mlx_new_window(game->vars.mlx, \
	game->map.n_column * 30, game->map.n_line * 30, "So_Long");
	game->player.img = mlx_xpm_file_to_image(game->vars.mlx, PLAYER, \
	&game->player.width, &game->player.height);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, FLOOR, \
	&game->floor.width, &game->floor.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, WALL, \
	&game->wall.width, &game->wall.height);
	game->item.img = mlx_xpm_file_to_image(game->vars.mlx, ITEM, \
	&game->item.width, &game->item.height);
	game->exit.img = mlx_xpm_file_to_image(game->vars.mlx, EXIT, \
	&game->exit.width, &game->exit.height);
}
