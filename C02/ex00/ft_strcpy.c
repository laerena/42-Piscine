/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:52:14 by leilai            #+#    #+#             */
/*   Updated: 2025/08/21 17:56:58 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

/*
#include <stdio.h>
int	main()
{
	char	d[20];
	char	s[] = "abcde";

	printf("%s\n", ft_strcpy(d, s));
}
*/
