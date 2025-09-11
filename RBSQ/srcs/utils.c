/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:31:35 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 20:31:37 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, src);
	return (res);
}

// int	main()
// {
// 	char p[] = "papapalklklklk11111";
// 	char *s;
// 	s =	ft_strdup(p);
// 	printf("%s", s);
// }
