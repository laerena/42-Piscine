/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:49:29 by leilai            #+#    #+#             */
/*   Updated: 2025/08/24 19:24:52 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	line(int x, int y);

void	rush(int x, int y)
{
	if ((x < 0) || (y < 0))
	{
		write(1, &"Please choose a positive int.", 38);
		return ;
	}
	line(x, y);
}

void	line(int x, int y)
{
	int	col;
	int	row;

	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 || row == y) && (col == 1 || col == x))
				ft_putchar('o');
			else if (col == 1 || col == x)
				ft_putchar('|');
			else if (row == 1 || row == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
