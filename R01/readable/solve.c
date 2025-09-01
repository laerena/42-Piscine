/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:44:31 by leilai            #+#    #+#             */
/*   Updated: 2025/09/01 13:04:45 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

int		dup_row(int **grid, int row, int n, int s);
int		dup_col(int **grid, int col, int n, int s);
int		check_row(int **grid, int row, int *left, int *right, int s);
int		check_col(int **grid, int col, int *top, int *bottom, int s);

int	valid(int **grid, int row, int col, int n, int s, int *top, int *bottom, int *left, int *right)
{
	if ((dup_row(grid, row, n, s)) || (dup_col(grid, col, n, s)))
		return (0);
	grid[row][col] = n; // temporary
	if ((!(check_row(grid, row, left, right, s))) || (!(check_col(grid, col, top, bottom, s))))
	{
		grid[row][col] = 0;
		return (0);
	}
	grid[row][col] = 0;
	return (1);
}

int	solve(int **grid, int row, int col, int s, int *top, int *bottom, int *left, int *right)
{
	int	now;
	int	next_r;
	int	next_c;

	if (row == s) // base case once all rows are filled
		return (1);
	next_r = row;
	next_c = col + 1;
	if (next_c == s)
	{
		next_r = row + 1;
		next_c = 0;
	}
	now = 1;
	/*
	while now < size
		try placing now at location grid[row][col]
		if valid;
			placed;
			recurse;
		now++; try now+1 at location
	*/
	while (now <= s)
	{
		if (valid(grid, row, col, now, s, top, bottom, left, right))
		{
			grid[row][col] = now;
			// recursion happens here we go to the top and do next_r and next_c
			if (solve(grid, next_r, next_c, s, top, bottom, left, right))
				return (1); // the end when base case match = propagation!
			grid[row][col] = 0; // undo placement of now to backtrack
		}
		now++;
	}
	return (0); // nope nothing works
}
// f recursion im dead this better work or im %$#&@*
