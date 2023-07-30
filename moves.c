/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:51:22 by rugoncal          #+#    #+#             */
/*   Updated: 2023/07/09 21:16:35 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function is triggered when user pushes "move_up" on keyboard.*/

void	move_up(t_game *map)
{
	int	x;
	int	i;

	x = map->width + 1;
	i = 0;
	while (map->map[i] != 'P')
		i++;
	if (map->map[i - x] == 'E' && map->max_score == map->score)
	{
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
		write(1, "\nCongrats, you won! 🏆\n", 25);
		end_game(map);
	}
	if (map->map[i - x] != '1' && map->map[i - x] != 'E')
	{
		if (map->map[i - x] == 'C')
			map->score++;
		map->map[i] = '0';
		map->map[i - x] = 'P';
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
	}
}

/* This function is triggered when user pushes the "move_down" on keyboard.*/

void	move_down(t_game *map)
{
	int	x;
	int	i;

	x = map->width + 1;
	i = 0;
	while (map->map[i] != 'P')
		i++;
	if (map->map[i + x] == 'E' && map->max_score == map->score)
	{
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
		write(1, "\nCongrats, you won! 🏆\n", 25);
		end_game(map);
	}
	if (map->map[i + x] != '1' && map->map[i + x] != 'E')
	{
		if (map->map[i + x] == 'C')
			map->score++;
		map->map[i] = '0';
		map->map[i + x] = 'P';
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
	}
}

/* This function is triggered when user pushes the "move_right" on keyboard.*/

void	move_right(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[i] != 'P')
		i++;
	if (map->map[i + 1] == 'E' && map->max_score == map->score)
	{
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
		write(1, "\nCongrats, you won! 🏆\n", 25);
		end_game(map);
	}
	if (map->map[i + 1] != '1' && map->map[i + 1] != 'E')
	{
		if (map->map[i + 1] == 'C')
			map->score++;
		map->map[i] = '0';
		map->map[i + 1] = 'P';
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
	}
}

/* This function is triggered when user pushes the "left" on keyboard.*/

void	move_left(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[i] != 'P')
		i++;
	if (map->map[i - 1] == 'E' && map->max_score == map->score)
	{
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
		write(1, "\nCongrats, you won! 🏆\n", 25);
		end_game(map);
	}
	if (map->map[i - 1] != '1' && map->map[i - 1] != 'E')
	{
		if (map->map[i - 1] == 'C')
			map->score++;
		map->map[i] = '0';
		map->map[i - 1] = 'P';
		map->moves++;
		write(1, "\nMoves: ", 8);
		ft_putnbr_fd(map->moves, 1);
	}
}
