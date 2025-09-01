/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:02:38 by leilai            #+#    #+#             */
/*   Updated: 2025/08/21 15:29:12 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

/*
#include <stdlib.h>
#include <stdio.h>

int     main()
{
        char    *str = malloc(8);
        str = "abcdef";
	printf("%d\n", ft_strlen(str));

}
*/
