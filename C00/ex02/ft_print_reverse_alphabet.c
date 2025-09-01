/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:37:38 by leilai            #+#    #+#             */
/*   Updated: 2025/08/19 11:41:14 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 122;
	while (c <= 122 && c >= 97)
	{
		write(1, &c, 1);
		c--;
	}
}

/*
int	main()
{
	ft_print_reverse_alphabet();
	return (0);
}
*/
