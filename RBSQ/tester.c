/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:34:15 by leilai            #+#    #+#             */
/*   Updated: 2025/09/08 23:56:53 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ut.h"

t_square	solver(t_map *map);

char	**make_tg(void)
{
	char **grid = malloc(sizeof(char *) * 4);
	grid[0] = strdup("...o.....");
	grid[1] = strdup(".....o...");
	grid[2] = strdup("....o.o..");
	grid[3] = strdup(".........");
	return (grid);
}
void	free_tg(char **grid, int rows)
{
	int i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	print_g(char **grid, int rows)
{
	int	i;
	
	i = 0;
	while (i < rows)
	{
		printf("%s\n", grid[i]);
		i++;
	}
}

int	main()
{
	t_map	map;
	map.rows = 4;
	map.cols = 9;
	map.empty = '.';
	map.obstacle = 'o';
	map.full = 'x';
	map.grid = make_tg();

	solver(&map);
	print_g(map.grid, map.rows);
	free_tg(map.grid, map.rows);
	return 0;
}
