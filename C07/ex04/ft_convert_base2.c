/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:12:00 by leilai            #+#    #+#             */
/*   Updated: 2025/09/09 14:31:33 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] > 9 && str[i] <= 13) || str[i] == 32)
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
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b;
	int	result;
	int	sign;
	int	i;
	int	pos;

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

int	count_len(long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*res;
	int		neg;
	int		len;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = count_len(n, ft_strlen(base));
	res = malloc(sizeof(char) * (len + neg + 1));
	if (!res)
		return (NULL);
	res[len + neg] = '\0';
	while (len > 0)
	{
		res[len + neg - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
