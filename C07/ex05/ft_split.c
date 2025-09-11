/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:32:37 by leilai            #+#    #+#             */
/*   Updated: 2025/09/10 23:09:48 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset);
int		count_s(char *str, char *charset);
void	write_s(char *dest, char *src, char *charset);
void	write_split(char **split, char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		cc;

	cc = count_s(str, charset);
	res = malloc(sizeof(char *) * (cc + 1));
	res[cc] = 0;
	write_split(res, str, charset);
	return (res);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_s(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && is_sep(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

void	write_s(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	cc;

	cc = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_sep(str[i + j], charset) == 0)
				j++;
			split[cc] = malloc(sizeof(char) * (j + 1));
			write_s(split[cc], str + i, charset);
			i += j;
			cc++;
		}
	}
}
/*
#include <stdio.h>
int	main()
{
	int	i;

	i = 0;
	char tsp[] = "aaaobbbbbooccccco";
	char charset[] = "owi";

	char **s = ft_split(tsp, charset);
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}
*/
