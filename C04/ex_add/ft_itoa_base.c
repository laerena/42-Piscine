/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 00:27:17 by leilai            #+#    #+#             */
/*   Updated: 2025/09/09 12:32:22 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_len(long n, int base);
int	ft_strlen(char *str);

char	*ft_itoa_base(int nb, char *base)
{
	char	*res;
	long	n;
	int	len;
	int	neg;
	int	b;

	b = ft_strlen(base);
	if (b < 2 || b > 16)
		return (NULL);
	n = nb;
	neg = 0;
	if (n < 0 && b == 10)
	{
		neg = 1;
		n = -n;
	}
	len = count_len(n, b);
	res = malloc(sizeof(char) * (len + neg + 1));
	if (!res)
		return (NULL);
	res[len + neg] = '\0';
	while (len > 0)
	{
		res[len + neg - 1] = base[n % b];
		n = n / b;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

int	count_len(long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa_base(225, "01234567"));
}
