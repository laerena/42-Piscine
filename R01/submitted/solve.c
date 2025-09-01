/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:44:31 by leilai            #+#    #+#             */
/*   Updated: 2025/08/31 20:51:17 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_puzzle
{
	int	**grid;
	int	s;
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
}	puzzle;

int	dup_row(puzzle *p, int row, int n);
int	dup_col(puzzle *p, int col, int n);
int	check_row(puzzle *p, int row);
int	check_col(puzzle *p, int col);

int	valid(puzzle *p, int row, int col, int n)
{
	if ((dup_row(p, row, n)) || (dup_col(p, col, n)))
		return (0);
	p->grid[row][col] = n;
	if ((!(check_row(p, row))) || (!(check_col(p, col))))
	{
		p->grid[row][col] = 0;
		return (0);
	}
	p->grid[row][col] = 0;
	return (1);
}

int	solve(puzzle *p, int row, int col)
{
	int	now;
	int	next_r;
	int	next_c;

	if (row == p->s)
		return (1);
	next_r = row;
	next_c = col + 1;
	if (next_c == p->s)
	{
		next_r = row + 1;
		next_c = 0;
	}
	now = 1;
	while (now <= p->s)
	{
		if (valid(p, row, col, now))
		{
			p->grid[row][col] = now;
			if (solve(p, next_r, next_c))
				return (1);
			p->grid[row][col] = 0;
		}
		now++;
	}
	return (0);
}
