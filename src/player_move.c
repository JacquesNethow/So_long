/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:28:07 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 22:45:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, --line, col);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, line, --col);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, ++line, col);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, line, ++col);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_click(game);
	return (0);
}

void	move_player(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (check_move(game, line, col) == 1)
	{
		if (game->map.map[line][col] == 'C')
			game->map.items--;
		game->map.map[y][x] = '0';
		game->map.player.y = line;
		game->map.player.x = col;
		render_game(game);
	}
}

int	check_move(t_game *game, int line, int col)
{
	if (game->map.map[line][col] == 'E' &&
		game->map.items == 0)
	{
		ft_putstr_fd("\033[0;32mVICTORY!!\n\033[0m", 1);
		exit_click(game);
	}
	if (game->map.map[line][col] != 'E' &&
		game->map.map[line][col] != '1')
	{
		game->n_moviment++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(game->n_moviment, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else
		return (0);
}
