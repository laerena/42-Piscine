
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int	check_int(char *line, int len)
{
	int		i;
	long	nb;

	nb = 0;
	while (i < (line - 3))
	{
		nb = (nb * 10) + (line[i] - '0');
		if (nb > 2147483647)
			return (0);
		i++;
	}
	return (1);



}



int	check_array(char **array)
{
	int	ok;
	int	len;
	int	i;

	if (!array || !array[0] || ft_strlen(array[i]) < 4
			|| !('0' < array[0][0] && array[0][0] < '9'))
		return (0);
	i = 0;
	len = ft_strlen(array[0]);
	ok = check_int(array[0], len);
	while (ok && '0' < array[0][i] && array[0][i] < '9')
		i++;
}

/* int result : s'incrementer | voit l'avancement 56
* 100 - 80 = 20  */