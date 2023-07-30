/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:34:29 by rugoncal          #+#    #+#             */
/*   Updated: 2023/07/24 20:52:02 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function starts the game.*/

void	start_game(char *map, t_game *game)
{
	int	fd;

	if (!check_ext(map))
		ft_error("Error\nMust be a .ber file.\n", game);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFile not found.\n", game);
	read_map(fd, game);
	play_game(game);
}

void	player_pos(t_game	*game)
{
	int	x;
	int	y;

	y = 1;
	while (y < game->height - 1 && game->players == 1)
	{
		x = 0;
		while (x <= game->width + 1)
		{
			if (game->map[(game->width + 2) * y + x] == 'P')
			{
				game->start_player_x = x;
				game->start_player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/* This function read the map file, line by line. */

void	read_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	char	**map;

	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nInvalid map!\n", game);
	while (line != NULL)
		game->width = check_line(game, &line, fd);
	check_game(game);
	i = 0;
	while (game->map[fd++])
	{
		if (game->map[fd] == 'C')
			game->max_score++;
		if (game->map[fd] == 'P')
			game->players++;
		if (game->map[fd] == 'E')
			i++;
	}
	player_pos(game);
	map = ft_split(game->map, '\n');
	check_path(game, map, game->start_player_x, game->start_player_y);
	ft_error_map(game, i);
	ft_free(map);
}

/* mlx_init() returns a pointer, a lot of the library functions needs it.
mlx_hook() allows to hook some of functions to certain events.
mlx_loop() is an infinite loop that would keep the program running.
Any code written after the call to this function would never be executed.*/

void	play_game(t_game *map)
{
	map->width = map->width + 1;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 100 * map->width, \
	100 * map->height, "so_long by rugoncal - and thanks for all the fish!");
	render_images(map);
	render_map(map, 0);
	mlx_hook(map->win, 17, 0, end_game, map);
	mlx_key_hook(map->win, check_key, map);
	mlx_loop(map->mlx);
}

/* This function ends the game. */

int	end_game(t_game *map)
{
	free(map->map);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	if (map->mlx)
		free(map->mlx);
	exit(0);
	return (0);
}
