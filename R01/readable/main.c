/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:19:02 by fdcurot           #+#    #+#             */
/*   Updated: 2025/09/01 12:14:02 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		parse(char *str, int *s, int **top, int **bottom, int **left, int **right);
int		solve(int **grid, int row, int col, int s, int *top, int *bottom, int *left, int *right);
void	print(int **grid, int s);

int	main(int ac, char **av)
{
	int	s; // s for size of grid - parse for value from input
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
	int	**grid;
	int	i;
	int	j;

	if (ac != 2 || !parse(av[1], &s, &top, &bottom, &left, &right))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	grid = malloc(sizeof(int *) * s); // first allocate mem for row pointer
	while (i < s)
	{
		grid[i] = malloc(sizeof(int) * s);// then each row is array of ints
		j = 0;
		while (j < s)
		{
			grid[i][j] = 0;// to avoid garbage value, calloc initialize malloc don't
			j++;
		}
		i++;
	}
	if (solve(grid, 0, 0, s, top, bottom, left, right))
		print(grid, s);
	else
		write(1, "Error\n", 6);
	// free step by step
	free(top);
	free(bottom);
	free(left);
	free(right);
	i = 0;
	while (i < s)
		free(grid[i++]);
	free(grid);
	return (0);
}

// parced input values
// grid malloc
// Error handling
// solve
// print
