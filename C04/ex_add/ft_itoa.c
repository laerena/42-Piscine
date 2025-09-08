/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:38:43 by leilai            #+#    #+#             */
/*   Updated: 2025/09/08 13:14:28 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_len(long n);

char	*ft_itoa(int nb)
{
	char	*res;
	int	count;
	int	i;
	long	n;

	n = nb;
	count = count_len(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	if (!(res = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		i++;
	}
	while (count > i)
	{
		count--;
		res[count] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

int	count_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(0));
}
