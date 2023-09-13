#include "./libft.h"

/**
 * Locates the first occurrence of the character searchedChar in the string.
 * @param	string	String to be searched.
 * @param	searchedChar	Character to be located.
 * @return	Returns a pointer to the first occurrence of the character in the string, or NULL if the character is not found.
 */
char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	if ((char)c == string[i])
		return ((char *)string);
	while ((char)c != string[i])
	{
		if (!string[i])
			return (0);
		i++;
	}
	return ((char *)string + i);
}
