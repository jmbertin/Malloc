#include "./libft.h"

/**
 * Checks if the given character is printable, including space.
 * @param	character	Character to be checked.
 * @return	Returns non-zero if the character is printable, 0 otherwise.
 */
int	ft_isprint(int character)
{
	if (character < 32 || character > 126)
		return (0);
	return (1);
}
