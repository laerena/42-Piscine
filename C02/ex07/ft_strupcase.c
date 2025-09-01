/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:55:00 by leilai            #+#    #+#             */
/*   Updated: 2025/08/25 12:00:15 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (tmp);
}

/*
#include <stdio.h>

int	main()
{
	char	s[] = "abcA8n";
	printf("%s\n", ft_strupcase(s));
	return 0;
}
*/
