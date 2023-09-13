#include "./libft.h"

/**
 * Converts the given character to uppercase if it is lowercase.
 * @param	c	Character to be converted.
 * @return	Returns the uppercase version of the character if it is lowercase, otherwise returns the character itself.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
