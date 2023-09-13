#include "./libft.h"

/**
 * Checks if the given character is alphanumeric (either a digit or an alphabetic character).
 * @param	arg	Character to be checked.
 * @return	Returns non-zero if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int arg)
{
	if (ft_isalpha(arg) || ft_isdigit(arg))
		return (1);
	return (0);
}
