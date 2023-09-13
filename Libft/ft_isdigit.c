#include "./libft.h"

/**
 * Checks if the given character is a digit (0 through 9).
 * @param	arg	Character to be checked.
 * @return	Returns non-zero if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int arg)
{
	if (arg < '0' || arg > '9')
		return (0);
	return (1);
}
