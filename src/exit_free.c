/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:14:24 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 22:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	exit_error(char *s)
{
	ft_putstr_fd("\033[0;31m", 1);
	ft_putstr_fd("Error! :", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n\033[0m", 1);
	exit(EXIT_FAILURE);
}

int	exit_click(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->n_moviment, 1);
	ft_putchar_fd('\n', 1);
	free_map(game);
	free_images(game);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.n_line)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

void	free_images(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.mlx_win);
	mlx_loop_end(game->vars.mlx);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->floor.img);
	mlx_destroy_image(game->vars.mlx, game->exit.img);
	mlx_destroy_image(game->vars.mlx, game->item.img);
	mlx_destroy_image(game->vars.mlx, game->player.img);
	mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}
