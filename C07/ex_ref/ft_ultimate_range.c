//int **range - a pointer to a pointer to int
//*range - a pointer to int (what range points to)
//**range - an int (the actual value)

#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	size;

	if (min >= max)
	{
		*range = NULL; // set the caller pointer to NULL
		return (0);
	}
	size = max - min;
	array = malloc(sizeof(int) * size);
	if (!array)
	{
		*range = NULL;
		return (-1);
	}
	//logic
	*range = array;
	return (size);
}
