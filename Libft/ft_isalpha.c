#include "./libft.h"

/**
 * Checks if the given character is an alphabetic character.
 * @param	arg	Character to be checked.
 * @return	Returns non-zero if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int arg)
{
	if (arg < 65 || (arg > 90 && arg < 97) || arg > 122)
		return (0);
	return (1);
}
