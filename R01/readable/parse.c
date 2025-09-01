/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:39:51 by leilai            #+#    #+#             */
/*   Updated: 2025/09/01 13:01:16 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

// to parse the command line inputs
// for example:  "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// to: top[4] = {4, 3, 2, 1}; bottom[4] = {1, 2, 2, 2}; ...

#include <stdlib.h>
#include <unistd.h>

int	parse(char *str, int *s, int **top, int **bottom, int **left, int **right)
{
	int		count;
	char	*tmp;
	int		i;
	int		v;

	count = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp >= '1' && *tmp <= '9')
			count++;
		else if (*tmp != ' ')
			return (0);
		tmp++;
	}
	if (count % 4 != 0 || count == 0)
		return (0);
	*s = count / 4;
	*top = malloc(sizeof(int) * (*s));
	*bottom = malloc(sizeof(int) * (*s));
	*left = malloc(sizeof(int) * (*s));
	*right = malloc(sizeof(int) * (*s));
	if (!*top || !*bottom || !*left || !*right)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= (*s + '0'))
		{
			v = *str - '0';
			if (i < *s)
				(*top)[i] = v;
			else if (i < 2 * (*s))
				(*bottom)[i - (*s)] = v;
			else if (i < 3 * (*s))
				(*left)[i - 2 * (*s)] = v;
			else
				(*right)[i - 3 * (*s)] = v;
			i++;
		}
		str++;
	}
	return (i == 4 * (*s));
}
