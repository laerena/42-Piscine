/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:27:08 by leilai            #+#    #+#             */
/*   Updated: 2025/08/19 20:31:51 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 97;
	while (c >= 97 && c <= 122)
	{
		write(1, &c, 1);
		c++;
	}
}

/*
int	main()
{
	ft_print_alphabet();
	return(0);
}
*/
