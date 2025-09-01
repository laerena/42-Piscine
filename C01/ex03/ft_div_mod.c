/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:05:18 by leilai            #+#    #+#             */
/*   Updated: 2025/08/21 12:55:24 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	int	i;
	int	j;
	int	*v = malloc(sizeof(int));
	int	*m = malloc(sizeof(int));

	i = 13;
	j = 3;
	ft_div_mod(i, j, v, m);
	printf("%d\n", *v);
	printf("%d\n", *m);
	return 0;
}
*/
