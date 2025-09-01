/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:42:23 by leilai            #+#    #+#             */
/*   Updated: 2025/08/19 11:47:57 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	i;

	i = 48;
	while (i >= 48 && i <= 57)
	{
		write(1, &i, 1);
		i++;
	}
}

/*
int	main()
{
	ft_print_numbers();
	return (0);
}*/
