/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:43 by rugoncal          #+#    #+#             */
/*   Updated: 2023/07/12 14:04:39 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function renders the images. */

void	render_images(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &i, &i);
	map->item = mlx_xpm_file_to_image(map->mlx, "textures/fish.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "textures/ground.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", \
	&i, &i);
	if (!map->wall || !map->exit || !map->item || !map->player || !map->space)
	{
		free(map->win);
		free(map->mlx);
		ft_error("Error\nImage file is missing!\n", map);
		exit(EXIT_FAILURE);
	}
}

/* This function renders the map.*/

void	render_map(t_game *map, int i)
{
	int		x;
	int		y;
	char	*s;

	y = -1;
	while (++y < map->height)
	{
		x = 0;
		while (x <= map->width)
		{
			if (map->map[i] == '1')
				s = map->wall;
			if (map->map[i] == '0')
				s = map->space;
			if (map->map[i] == 'C')
				s = map->item;
			if (map->map[i] == 'P')
				s = map->player;
			if (map->map[i] == 'E')
				s = map->exit;
			mlx_put_image_to_window(map->mlx, map->win, s, x * 100, y * 100);
			i++;
			x++;
		}
	}
}

/* This function initialize the values with NULL.*/

void	init_value(t_game *game)
{
	game->map = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->item = NULL;
	game->player = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->gameover = 0;
	game->moves = 0;
	game->score = 0;
	game->max_score = 0;
	game->can_collect = 0;
	game->can_exit = 0;
	game->start_player_x = 0;
	game->start_player_y = 0;
}
