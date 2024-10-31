/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:12 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 23:34:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	render_game(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(
		game->vars.mlx, game->vars.mlx_win, game->player.img,
		game->map.player.x * 30, game->map.player.y * 30);
	return (0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win,
					game->floor.img, x * 30, y * 30);
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win,
					game->wall.img, x * 30, y * 30);
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win,
					game->item.img, x * 30, y * 30);
			if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win,
					game->exit.img, x * 30, y * 30);
			x++;
		}
		y++;
	}
}
