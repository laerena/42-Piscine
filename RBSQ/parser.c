/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:19:36 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 09:39:47 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ut.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str);

int	ft_atoi_n(char *str, int len)
{
	int	i;
	int	n;
	
	i = 0;
	n = 0;
	while (i < len && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);

}

int	parser(char **array_map, t_map *map)
{
	int	len;
	char	*line;
	
	len = 0;
	line = array_map[0];
	if (!line)
		return (0);
	while (line[len])
		len++;
	if (len < 4)
		return (0);
	map->rows = ft_atoi_n(line, len - 3);
	map->empty = line[len - 3];
	map->obstacle = line[len - 2];
	map->full = line[len - 1];
	map->cols = ft_strlen(array_map[1]);
	return (1);
}
