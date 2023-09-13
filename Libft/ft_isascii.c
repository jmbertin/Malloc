#include "./libft.h"

/**
 * Checks if the given character is a valid ASCII character.
 * @param	arg	Character to be checked.
 * @return	Returns non-zero if the character is ASCII, 0 otherwise.
 */
int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
		return (1);
	return (0);
}
