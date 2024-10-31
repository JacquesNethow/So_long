/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.43sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:43:31 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 23:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define KEY_ESC	65307
# define KEY_Q		113
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define PLAYER		"./assets/sprites/player.xpm"
# define FLOOR		"./assets/sprites/floor.xpm"
# define WALL		"./assets/sprites/wall.xpm"
# define ITEM		"./assets/sprites/item.xpm"
# define EXIT		"./assets/sprites/Exit.xpm"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	t_position	position;
}	t_img;

typedef struct s_map
{
	int			n_column;
	int			n_line;
	int			items;
	int			exit;
	int			n_player;
	char		**map;
	t_position	player;
}	t_map;

typedef struct s_mlx_var
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_Var;

typedef struct s_game
{
	int			n_moviment;
	t_mlx_Var	vars;
	t_img		player;
	t_img		floor;
	t_img		wall;
	t_img		exit;
	t_img		item;
	t_map		map;
}	t_game;

void	init_vars(t_game *game);

void	init_game(t_game *game);

void	read_map(char *argv, t_game *game);

void	count_column(t_game *game);

void	validate_map(t_game *game);

void	count_chars(int x, int y, t_game *game);

int		render_game(t_game *game);

void	render_map(t_game *game);

int		key_press(int keycode, t_game *game);

void	move_player(t_game *game, int line, int col);

int		check_move(t_game *game, int line, int col);

void	verify_argc(int argc);

void	verify_ext(char *map_name);

void	verify_count_chars(t_game *game);

void	verify_wall(t_game *game);

void	verify_issquare(t_game *game);

void	exit_error(char *s);

int		exit_click(t_game *game);

void	free_map(t_game *game);

void	free_images(t_game *game);

#endif
