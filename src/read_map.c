/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:36:05 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 16:46:02 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	read_map(char *argv, t_game *game)
{
	int		fd;
	char	*tmp_map;
	char	*tmp_line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit_error("file not opened");
	verify_ext(argv);
	tmp_map = ft_strdup("");
	game->map.n_line = 0;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		tmp_map = ft_strjoin(tmp_map, tmp_line);
		free(tmp_line);
		game->map.n_line++;
	}
	game->map.map = ft_split(tmp_map, '\n');
	free(tmp_map);
	count_column(game);
	validate_map(game);
	close(fd);
}

void	count_column(t_game *game)
{
	int	len_line;
	int	temp;
	int	i;

	game->map.n_column = 0;
	temp = 0;
	len_line = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i])
	{
		temp = ft_strlen(game->map.map[i]);
		if (len_line != temp)
		{
			free_map(game);
			exit_error("Invalid column size");
		}
		i++;
	}
	game->map.n_column = temp;
}

void	validate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (ft_strchr("01CEP", game->map.map[y][x]) == NULL)
			{
				free_map(game);
				exit_error("Invalid char");
			}
			count_chars(x, y, game);
			x++;
		}
		y++;
	}
	verify_wall(game);
	verify_count_chars(game);
	verify_issquare(game);
}

void	count_chars(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == 'E')
		game->map.exit++;
	if (game->map.map[y][x] == 'C')
		game->map.items++;
	if (game->map.map[y][x] == 'P')
	{
		game->map.n_player++;
		game->map.player.y = y;
		game->map.player.x = x;
	}
}
