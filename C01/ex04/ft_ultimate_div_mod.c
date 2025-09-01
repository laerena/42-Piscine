/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:23:30 by leilai            #+#    #+#             */
/*   Updated: 2025/08/21 12:57:31 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	int	*v = malloc(sizeof(int));
	int	*m = malloc(sizeof(int));
	int	i = 13;
	int	j = 3;

	v = &i;
	m = &j;
	
	ft_ultimate_div_mod(v, m);
	printf("%d\n", *v);
	printf("%d\n", *m);
	return 0;
}
*/
