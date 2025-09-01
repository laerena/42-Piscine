/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:06:17 by leilai            #+#    #+#             */
/*   Updated: 2025/08/28 12:07:36 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base);
int	verif(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		b;

	n = nbr;
	b = ft_strlen(base);
	if (verif(base))
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n >= b)
			ft_putnbr_base(n / b, base);
		write(1, &base[n % b], 1);
	}
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	int	nbr = 88;
	char	base[] = "poneyvif";
	ft_putnbr_base(nbr, base);
}
*/
