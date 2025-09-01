/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:48:14 by leilai            #+#    #+#             */
/*   Updated: 2025/08/20 14:57:51 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*
void    ft_putnbr(int nb)
{
        long    nbr;

        nbr = nb;
        if (nbr < 0)
        {
                write(1, "-", 1);
                nbr = -nbr;
        }
        if (nbr > 9)
                ft_putnbr(nbr / 10);
        write(1, &"0123456789"[nbr % 10], 1);
}

int	main()
{
	int number = 0;
	int *pointer1 = &number;
	int **pointer2 = &pointer1;
	int ***pointer3 = &pointer2;
	int ****pointer4 = &pointer3;
	int *****pointer5 = &pointer4;
	int ******pointer6 = &pointer5;
	int *******pointer7 = &pointer6;
	int ********pointer8 = &pointer7;
	int *********pointer9 = &pointer8;

	write(1, "Before: ", 8);
	ft_putnbr(number);
	write(1, "\n", 1);

	ft_ultimate_ft(pointer9);
	
	write(1, "After: ", 7);
	ft_putnbr(number);
	write(1, "\n", 1);
	
	return 0;
}*/
