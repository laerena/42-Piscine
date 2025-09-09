/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romousqu <romousqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:20:37 by romousqu          #+#    #+#             */
/*   Updated: 2025/09/09 18:05:28 by romousqu         ###   ########.fr       */
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
	while(already_read > 0)
	{
		already_read = read(fd, current, 10);
		current[already_read] = '\0';
		// printf("\ncurrent :\n%s\n", current);
		res = ft_str_njoin(res, current, already_read);
		if (!res)
			return (NULL);
	}

	close(fd);
	if (already_read < 0)
	{
		free(res);
		ft_error("read error\n", 0);
		return (NULL);
	}
	return (res);
}

// Main function where most of everything happens
// 
// First we open the current argv to a fd to extract the map into a char *map, 
// then, we split the first line into a new char *, the map is sent into a new char **array; 
// 
// then we check the dimensions (rectangle with the matching number of line), if each one of the char in the map match the argument
// 
// then i send the map to you 
//
int	bsq(char *file_name)
{
	int		fd;
	char	*pre_map;
	// char	*first_line;
	char	**array_map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error("Map error\n", 0));
	pre_map = read_string(fd);
	
	if (!pre_map /*&& !check_map(pre_map)*/)
	{
		if (pre_map)
			free(pre_map);
		return (ft_error("Map error\n", 0));
	}
	printf("\nPremap : \n%s\n\n", pre_map);
	
	array_map = ft_split(pre_map, '\n');
	print_array(array_map);							//map after split

	//check

	//you function
	//leilai(array_map, first_line);


	close (fd);
	free (pre_map);
	// free_array(array_map);
	return (1);
}


int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		ft_putstr("No argument\n");

	else
	{
		i = 1;
		while (i < argc)
		{
			if (i > 1)
				ft_putstr("\n\n");
			if (!bsq(argv[i]))
			{
				ft_putstr("map error\n");
			}
			i++;
		}	
	}
}

// char **;

// "oooooXoooooo"
// "oooXoooooooo"
// "ooXooooooooo"
// "oooooooooXoo"
// "ooooXooooooo"



