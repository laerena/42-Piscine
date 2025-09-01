/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:06:00 by leilai            #+#    #+#             */
/*   Updated: 2025/08/21 12:53:46 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
#include <stdio.h>
int	main()
{
	int	*a; //declare a pointer to store the address of an int 
	int	*b;
	int	i = 24; //assign a value to a normal int variable
	int	j = 42;

	a = &i; //store address of i at pointer a
	b = &j;

	ft_swap(a, b);
	printf("%d\n", *a); //dereferencing
	printf("%d\n", *b); //to access the value present at memory address
	return 0;
}
*/
