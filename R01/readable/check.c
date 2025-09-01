/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:32:19 by leilai            #+#    #+#             */
/*   Updated: 2025/08/31 21:04:20 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// boolean function to flag if there are duplicates of n in the row
int	dup_row(int **grid, int row, int n, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		if (grid[row][i] == n)
			return (1);
		i++;
	}
	return (0);
}

// boolean to flag for dups in col
int	dup_col(int **grid, int col, int n, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		if (grid[i][col] == n)
			return (1);
		i++;
	}
	return (0);
}

// function return the current visibility: count
static int	vis_left(int *row, int s)
{
	int	i;
	int	count;
	int	max; //max amount of items that can be seen

	i = 0;
	count = 0;
	max = 0;
	while (i < s)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i++;
	}
	return (count);
}

static int	vis_right(int *row, int s)
{
	int	i;
	int	count;
	int	max;

	i = s - 1;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	return (count);
}

// if row is full check if vis comply with left and right
int	check_row(int **grid, int row, int *left, int *right, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		if (grid[row][i] == 0)
			return (1);
		i++;
	}
	if ((vis_left(grid[row], s) != left[row])
		|| (vis_right(grid[row], s) != right[row]))
		return (0);
	return (1);
}

// unfinished
int	check_col(int **grid, int col, int *top, int *bottom, int s)
{
	// not a contiguous array need to build a tmp one and shove the items in
	int	*tmp;
	int	i;
	int	full;

	tmp = malloc(sizeof(int) * s);
	if (!tmp)
		return (0);
	i = 0;
	full = 1;
	while (i < s)
	{
		tmp[i] = grid[i][col];
		if (tmp[i] == 0)
			full = 0;
		i++;
	}
	if (!full)
	{
		free(tmp);
		return (1);
	}
	//reset i and check full and blablabla similar to check_row but with tmp
	if ((vis_left(tmp, s) != top[col]) || (vis_right(tmp, s) != bottom[col]))
		return (0);
	free(tmp);
	return (1);
}
