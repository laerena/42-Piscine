/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romousqu <romousqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:20:37 by romousqu          #+#    #+#             */
/*   Updated: 2025/09/10 22:32:00 by romousqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
void	print_array(char **array);
char	**ft_split(char *str, char c);
void	solve(char **array_map);
int		free_array(char **array_map, int returned);
int		check_array(char **array);
int		free_str(char *str, int return_value);
int		finish_n_double_n(char *pre_map);
char	*free_str2(char *str, char *returned);

int	ft_error(char *msg, int return_value)
{
	ft_putstr(msg);
	return (return_value);
}

char	*ft_str_njoin(char *original, char *added, int n)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(sizeof(char) + (ft_strlen(original) + n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (original[i])
	{
		new[i] = original[i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		new[i + j] = added[j];
		j++;
	}
	new[i + j] = '\0';
	free (original);
	return (new);
}

//kinda
// 
char	*read_string(int fd)
{
	char	*res;
	char	current[1024];
	int		already_read;

	already_read = 1;
	res = ft_strdup("");
	while (already_read > 0)
	{
		already_read = read(fd, current, 1023);
		current[already_read] = '\0';
		if (!(res[0]) && already_read <= 0)
			return (free_str2(res, NULL));
		res = ft_str_njoin(res, current, already_read);
		if (!res)
			return (NULL);
	}
	close(fd);
	if (already_read < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

// Main function where most of everything happens
// 
// First we open the current argv to a fd to extract the map into a char *map, 
// then, we split the first line into a new char *,
//  the map is sent into a new char **array; 
// 
// then we check the dimensions (rectangle with the matching number of line), 
// if each one of the char in the map match the argument
// 
// then i send the map to you 
//
int	bsq(char *file_name, int no_arg)
{
	int		fd;
	char	*pre_map;
	char	**array_map;

	if (no_arg)
		pre_map = read_string(0);
	else
	{
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
			return (0);
		pre_map = read_string(fd);
	}
	if (!pre_map || !finish_n_double_n(pre_map))
		return (free_str(pre_map, 0));
	array_map = ft_split(pre_map, '\n');
	free(pre_map);
	if (!no_arg)
		close (fd);
	if (check_array(array_map))
		solve(array_map);
	else
		return (free_array(array_map, 0));
	return (free_array(array_map, 1));
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (!bsq(NULL, argc))
			ft_putstr("map error\n");
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!bsq(argv[i], 0))
			{
				ft_putstr("map error\n");
			}
			i++;
		}
	}
}
