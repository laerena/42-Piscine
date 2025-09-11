/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:27:56 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 20:27:57 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

int	ft_strlen_int(char *str)
{
	int		i;
	long	res;

	if (!str)
		return (0);
	res = 0;
	i = 0;
	while (str[i])
	{
		i++;
		res++;
		if (res > 2147483647)
			return (0);
	}
	return (i);
}

int	check_int_check_unique(char *line, int len)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (i < (len - 3))
	{
		nb = (nb * 10) + (line[i] - '0');
		if (nb > 2147483647)
			return (0);
		i++;
	}
	if (line[len - 1] == line[len - 2]
		|| line[len - 1] == line[len - 3]
		|| line[len - 3] == line[len - 2])
		return (0);
	return (nb);
}

int	check_matching_array(int nb_ligne, char c1, char c2, char **array)
{
	int	i;
	int	len_line;
	int	j;

	i = 1;
	len_line = ft_strlen_int(array[1]);
	if (!len_line)
		return (0);
	while (i <= nb_ligne)
	{
		if (array[i] == NULL || (ft_strlen_int(array[i]) != len_line))
			return (0);
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != c1 && array[i][j] != c2)
				return (0);
			j++;
		}
		i++;
	}
	if (array[i] != NULL)
		return (0);
	return (1);
}

int	check_array(char **array)
{
	int	ok;
	int	len;

	if (!array || !(array[0]) || ft_strlen_int(array[0]) < 4)
		return (0);
	len = ft_strlen(array[0]);
	ok = check_int_check_unique(array[0], len);
	if (ok == 0)
		return (0);
	if (!check_matching_array(ok, array[0][len - 3],
		array[0][len - 2], array))
		return (0);
	return (1);
}

//
// int main()
// {
// 	char **tab;
// 	// int ok = check_int_check_unique(s, ft_strlen(s));
//
// 	tab = (char **)malloc(sizeof(char *) * (7));
// 	if (!tab)
// 		return(0);
// 	tab[0] = ft_strdup("6oXe");
// 	tab[1] = ft_strdup("oooooXoooooo");
// 	tab[2] = ft_strdup("oooXoooooooo");
// 	tab[3] = ft_strdup("ooXooooooooo");
// 	tab[4] = ft_strdup("oooooooooXoo");
// 	tab[5] = ft_strdup("oooooXoooXoo");
// 	tab[6] = NULL;
//	
// 	// printf("tab0 =%s\n\n", tab[0]);
// 	// printf("oui\n\n");
// 	printf("\n---- final = %d ----\n\n", check_array(tab));
//
// 	int i = 0;
// 	while(tab[i])
// 		free(tab[i++]);
// 	if (tab)
// 		free (tab);
//
// }
// 
// 
// 
// 
// 
// 
// 
// "oooooXoooooo"
// "oooXoooooooo"
// "ooXooooooooo"
// "oooooooooXoo"
// "ooooXooooooo"
// 
// 
//doublon ok
// 
// limit int ok
//
// ligne 1 trop court ok
//
//to do
// line length
// number of line matching the first line
//
