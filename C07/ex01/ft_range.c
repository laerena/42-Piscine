/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:58:09 by leilai            #+#    #+#             */
/*   Updated: 2025/09/03 17:42:50 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*result;
	int	i;
	
	if (min >= max)
		return (0);
	result = malloc(sizeof(int) * (max - min));
	if (!result)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
int	main()
{
	int	i;
	int	*tab;

	tab = 0;
	tab = ft_range(0, 3);
	i = 0;
	while (i < (3))
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free(tab);
	tab = 0;
	return (0);
}
*/
