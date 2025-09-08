/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:03:29 by leilai            #+#    #+#             */
/*   Updated: 2025/09/08 19:21:02 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ut.h"

void	fill_s(t_map *map, t_square max);
int	min3(int a, int b, int c);
int	**allo_g(int row, int col);
void	free_g(int **grid, int row);

t_square	solver(t_map *map)
{
	int	**new;
	t_square	max;
	int	y;
	int	x;

	new = allo_g(map->rows, map->cols);
	y = 0;
	max.size = 0;
	max.row = 0;
	max.col = 0;
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
				new[y][x] = 1 + min3(new[y-1][x], new[y][x-1], new[y-1][x-1]);
			if (new[y][x] > max.size)
			{
				max.size = new[y][x];
				max.row = y;
				max.col = x;
			}
			x++;
		}
		y++;
	}
	fill_s(map, max);
	free_g(new, map->rows);
	return (max);
}
void	fill_s(t_map *map, t_square max)
{
	int	y;
	int	x;

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

int	min3(int a, int b, int c)
{
	int	mn;

	mn = a;
	if (b < mn)
		mn = b;
	if (c < mn)
		mn = c;
	return (mn);
}

int	**allo_g(int row, int col)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = malloc(sizeof(int *) * row);
	if (!grid)
		return (NULL);
	while (i < row)
	{
		grid[i] = malloc(sizeof(int) * col);
		j = 0;
		if (!grid[i])
		{
			while (j < i)
			{
				free(grid[j]);
				j++;
			}
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	free_g(int **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
