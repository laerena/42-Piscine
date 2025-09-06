/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:37:07 by leilai            #+#    #+#             */
/*   Updated: 2025/09/05 15:13:58 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s);
int	result_len(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	len;
	int	i;

	if (size == 0)
	{
		result = malloc(1);
		result = NULL;
		return (result);
	}
	len = result_len(size, strs, sep);
	result = malloc(len + 1);
	if (!result)
		return (result);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i + 1 < size)
			result = ft_strcat(result, sep);
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int	result_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1) + 1;
	return (len + 1);
}

#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello";
	char	str1[] = "World";
	char	str2[] = "!";
	char	*str012[] = {str, str1, str2};
	char	*result = ft_strjoin(3, str012, "-");

	printf("%s", result);
	free(result);
	return (0);
}

