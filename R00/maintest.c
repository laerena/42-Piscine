/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:07:25 by cgasser           #+#    #+#             */
/*   Updated: 2025/08/24 19:43:36 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int a, int b);

int	main(void)
{
	rush(5, 3);
	write(1, "\n", 1);
	rush(5, 1);
	write(1, "\n", 1);
	rush(1, 1);
	write(1, "\n", 1);
	rush(1, 5);
	write(1, "\n", 1);
	rush(4, 4);
	write(1, "\n", 1);
	rush('a', 5);
	write(1, "\n", 1);
	rush(0, 0);
	write(1, "\n", 1);
	rush(1, 0);
	write(1, "\n", 1);
	rush(0, 1);
	write(1, "\n", 1);
	rush(-1, 0);
	write(1, "\n", 1);
	rush(0, -1);
	write(1, "\n", 1);
	rush(-1, -5);
	return (0);
}
