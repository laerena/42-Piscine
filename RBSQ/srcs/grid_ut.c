/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_ut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romousqu <romousqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:20:40 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 19:38:48 by romousqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ut.h"
#include <unistd.h>
#include <stdlib.h>

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
