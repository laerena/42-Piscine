/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:31:41 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 20:31:44 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);

void	print_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			write(1, &array[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	free_array(char **tab, int returned)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
		free (tab);
	return (returned);
}

int	free_str(char *str, int ret)
{
	if (str)
		free (str);
	return (ret);
}

char	*free_str2(char *res, char *returned)
{
	if (res)
		free (res);
	return (returned);
}

int	finish_n_double_n(char *str)
{
	int	i;

	i = 0;
	if (str[(ft_strlen(str) - 1)] != '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
