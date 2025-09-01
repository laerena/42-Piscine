/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:46:31 by leilai            #+#    #+#             */
/*   Updated: 2025/08/26 17:21:57 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if ((!str[i - 1]) || (str[i - 1] < '0')
				|| (str[i - 1] > '9' && str[i - 1] < 'A')
				|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || (str[i - 1] > 'z'))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char	a[] = "9heLLO, how a+re you? 42words forty-two; fifty+and+one";

	printf("%s", ft_strcapitalize(a));
}*/
