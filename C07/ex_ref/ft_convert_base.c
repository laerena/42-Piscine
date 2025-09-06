/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:34:13 by leilai            #+#    #+#             */
/*   Updated: 2025/09/06 21:57:14 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	verif(char *base);
int	ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!verif(base_from)|| !verif(base_to))
		return (NULL);

	// Validate both bases
	// Parse nbr into decimal integer using base_from
	// Convert integer to string using base_to
    	// Handle negative numbers
}

char	*ft_itoa_base(int nbr, char *base)
{


int	verif(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
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
