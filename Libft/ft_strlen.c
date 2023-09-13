#include "./libft.h"

/**
 * Computes the length of the string str up to, but not including the terminating null character.
 * @param	str	Pointer to the string.
 * @return	Returns the number of characters in the string.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
