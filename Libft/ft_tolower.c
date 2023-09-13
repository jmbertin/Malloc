#include "./libft.h"

/**
 * Converts the given character to lowercase if it is uppercase.
 * @param	c	Character to be converted.
 * @return	Returns the lowercase version of the character if it is uppercase, otherwise returns the character itself.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
