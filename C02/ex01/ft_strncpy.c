/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:58:03 by leilai            #+#    #+#             */
/*   Updated: 2025/08/27 15:29:36 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char	d[] = "World1";
	char	s[] = "Heooo";

	printf("%s\n", ft_strncpy(d, s, 3));
	printf("%s\n", strncpy(d, s, 3));
}
*/
