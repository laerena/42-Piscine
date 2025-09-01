/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:40:08 by leilai            #+#    #+#             */
/*   Updated: 2025/08/25 11:16:36 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((!(*str >= 65 && *str <= 90)) && (!(*str >= 97 && *str <= 122)))
			return (0);
		str++;
	}
	return (1);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	*empty = malloc(sizeof(char));
	char	*alpha = "abc";
	char	*other = "abcghij[`aBCZ";

	printf("%i\n", ft_str_is_alpha(empty));
	printf("%i\n", ft_str_is_alpha(alpha));
	printf("%i\n", ft_str_is_alpha(other));
}
*/
