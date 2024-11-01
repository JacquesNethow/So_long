/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:52:28 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 22:44:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	verify_argc(int argc)
{
	if (argc > 2)
		exit_error("Too many arguments");
	if (argc < 2)
		exit_error("Mapfile is missing");
}

void	verify_ext(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] != '.' || map_name[len - 3] != 'b' || \
		map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
		exit_error("File Extension is wrong");
}

void	verify_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[0][x] != '1' || \
			game->map.map[game->map.n_line - 1][x] != '1')
			{
				free_map(game);
				exit_error("A horizontal Wall is missing");
			}
			if (game->map.map[y][0] != '1' || \
			game->map.map[y][game->map.n_column - 1] != '1')
			{
				free_map(game);
				exit_error("A vertical Wall is missing");
			}
			x++;
		}
		y++;
	}
}

void	verify_count_chars(t_game *game)
{
	if (game->map.n_player != 1)
	{
		free_map(game);
		exit_error("Invalid player quantity");
	}
	if (game->map.exit < 1)
	{
		free_map(game);
		exit_error("There are no exit");
	}
	if (game->map.items < 1)
	{
		free_map(game);
		exit_error("There are no collectibles");
	}
}

void	verify_issquare(t_game *game)
{
	if (game->map.n_column == game->map.n_line)
	{
		free_map(game);
		exit_error("Map is a square");
	}
}
