/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:05:45 by rugoncal          #+#    #+#             */
/*   Updated: 2023/07/28 22:05:47 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct s_game
{
	char	*map;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		moves;
	int		score;
	int		max_score;
	int		can_collect;
	int		can_exit;
	int		start_player_x;
	int		start_player_y;
}	t_game;

void	init_value(t_game *game);
void	start_game(char *map, t_game *game);
void	ft_error(char *str, t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	read_map(int fd, t_game *game);
void	play_game(t_game *game);
void	render_images(t_game *map);
void	render_map(t_game *map, int i);
void	move_up(t_game *map);
void	move_down(t_game *map);
void	move_right(t_game *map);
void	move_left(t_game *map);
void	check_game(t_game *game);
void	check_path(t_game *game, char **map, int x, int y);
void	ft_free(char **map);
void	ft_error_map(t_game *game, int i);
int		check_ext(char *map);
int		check_line(t_game *map, char **line, int fd);
int		check_key(int key, t_game *game);
int		end_game(t_game *map);
int		ft_strlen_2(char **s);
char	**ft_split(char const *s, char c);

#endif
