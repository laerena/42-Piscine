/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:10:39 by leilai            #+#    #+#             */
/*   Updated: 2025/09/08 12:35:32 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base);
int	verif(char *base);
int	base_location(char c, char *base);
int	skip(char *str, int *sign);

int	ft_atoi_base(char *str, char *base)
{
	int	b;
	int	result;
	int	sign;
	int	i;
	int	pos;

	if (!verif(base))
		return (0);
	b = ft_strlen(base);
	result = 0;
	sign = 1;
	i = skip(str, &sign);
	pos = base_location(str[i], base);
	while (pos != -1)
	{
		result = result * b + pos;
		i++;
		pos = base_location(str[i], base);
	}
	return (result * sign);
}

int	skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	base_location(char c, char *base)
{
	int	i;

	i = 0;
	if (verif(base))
	{
		while (base[i])
		{
			if (c == base[i])
				return (i);
			i++;
		}
	}
	return (-1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	verif(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2 || !base[i])
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	char	s[] = "123";
	char	base[] = "01234567";
	printf("%d\n", ft_atoi_base(s, base));
}
*/
