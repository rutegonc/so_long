/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:04:57 by rugoncal          #+#    #+#             */
/*   Updated: 2023/07/28 22:05:00 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if the map extension is valid. */

int	check_ext(char *map)
{
	int		i;
	char	*file_ext;

	file_ext = ".ber";
	i = 0;
	while (ft_strlen(map) != 4 && map)
		map++;
	if (!map || *map == '\0')
		return (0);
	while (map[i])
	{
		if (map[i] != file_ext[i])
			return (0);
		i++;
	}
	return (1);
}

/* This function checks if the map is legal. */

int	check_line(t_game *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((*line)[i] != '1')
		ft_error("Error\nInvalid map!\n", map);
	while ((*line)[i + 1] && (*line)[i + 1] != '\n')
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P')
			ft_error("Error\nInvalid characters in map.\n", map);
		i++;
	}
	tmp = map->map;
	map->map = ft_strjoin(tmp, *line);
	free(*line);
	if (i != map->width && map->width != 0)
		ft_error("Error\nInvalid map!\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

/* This function checks in general if everything is legal on game.*/

void	check_game(t_game *game)
{
	int	i;
	int	j;

	i = game->width;
	while (i >= 0)
	{
		if (game->map[i] != '1')
			ft_error("Error\nInvalid map!\n", game);
		i--;
	}
	j = game->height;
	while (j >= 0)
	{
		if (game->map[j] != '1')
			ft_error("Error\nInvalid map!\n", game);
		j--;
	}
	if (game->width > 26 || game->height > 14)
		ft_error("Error\nMap doesn't fit to window!\n", game);
}

/* This function detects which key was pressed by the user. */

int	check_key(int key, t_game *map)
{
	if (key == XK_Escape)
		end_game(map);
	else if (key == XK_Up || key == XK_w)
		move_up(map);
	else if (key == XK_Down || key == XK_s)
		move_down(map);
	else if (key == XK_Left || key == XK_a)
		move_left(map);
	else if (key == XK_Right || key == XK_d)
		move_right(map);
	mlx_clear_window(map->mlx, map->win);
	render_map(map, 0);
	return (0);
}

/* This function checks if the player path is valid. */

void	check_path(t_game *game, char **map, int x, int y)
{
	if (game->height >= y && game->width >= x)
	{
		if (map[y][x] == 'E')
			game->can_exit = 1;
		if (map[y][x] == '1' || map[y][x] == 'E')
			return ;
		if (map[y][x] == 'C')
			game->can_collect++;
		map[y][x] = '1';
	}
	check_path(game, map, x - 1, y);
	check_path(game, map, x + 1, y);
	check_path(game, map, x, y - 1);
	check_path(game, map, x, y + 1);
}
