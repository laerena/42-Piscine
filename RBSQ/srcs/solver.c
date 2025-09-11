/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romousqu <romousqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:03:29 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 20:31:23 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ut.h"

void	fill_s(t_map *map, t_square max);
int		min3(int a, int b, int c);
int		**allo_g(int row, int col);
void	free_g(int **grid, int row);
void	update_max(int **new, int y, int x, t_square *max);
int		**builder(t_map *map, t_square *max);

t_square	solver(t_map *map)
{
	t_square	max;
	int			**new;

	max.size = 0;
	max.row = 0;
	max.col = 0;
	new = builder(map, &max);
	fill_s(map, max);
	free_g(new, map->rows);
	return (max);
}

int	**builder(t_map *map, t_square *max)
{
	int	**new;
	int	y;
	int	x;

	new = allo_g(map->rows, map->cols);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == map->obstacle)
				new[y][x] = 0;
			else if (y == 0 || x == 0)
				new[y][x] = 1;
			else
				new[y][x] = 1 + min3
					(new[y - 1][x], new[y][x - 1], new[y - 1][x - 1]);
			update_max(new, y, x, max);
			x++;
		}
		y++;
	}
	return (new);
}

void	update_max(int **new, int y, int x, t_square *max)
{
	if (new[y][x] > max->size)
	{
		max->size = new[y][x];
		max->row = y;
		max->col = x;
	}
}

void	fill_s(t_map *map, t_square max)
{
	int	y;
	int	x;

	if (max.size <= 0)
		return ;
	y = max.row;
	while (y > max.row - max.size)
	{
		x = max.col;
		while (x > max.col - max.size)
		{
			map->grid[y][x] = map->full;
			x--;
		}
		y--;
	}
}
