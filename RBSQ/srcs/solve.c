/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romousqu <romousqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:05:20 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 20:29:42 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/ut.h"

t_square	solver(t_map *map);
int			parser(char **array_map, t_map *map);

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->grid[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

void	solve(char **array_map)
{
	t_map	map;

	parser(array_map, &map);
	solver(&map);
	print_map(&map);
}
