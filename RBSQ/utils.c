#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, src);
	return (res);
}

// int	main()
// {
// 	char p[] = "papapalklklklk11111";
// 	char *s;
// 	s =	ft_strdup(p);
// 	printf("%s", s);
// }
