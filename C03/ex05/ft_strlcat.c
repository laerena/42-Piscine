/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:01 by leilai            #+#    #+#             */
/*   Updated: 2025/09/01 14:10:03 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;

	i = 0;
	slen = 0;
	j = 0;
	if (!dest || !src)
		return (0);
	while (dest[i] && i < size)
		i++;
	while (src[slen])
		slen++;
	if (i == size)
		return (size + slen);
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + slen);
}

#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	//strlcat return the len wanted
	//while dest return destlen < size
	char d[] = "aa"; //character array that can be modified
	char *s = "bb"; //string literal is stored in read-only memory
	unsigned int n = 3;
	printf("%i\n", ft_strlcat(d, s, n));
	printf("%s\n", d);
}
//to compile use cc -lbsd <filename>
