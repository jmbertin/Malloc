#include "./libft.h"

/**
 * Locates the last occurrence of the character searchedChar in the string.
 * @param	string	String to be searched.
 * @param	searchedChar	Character to be located.
 * @return	Returns a pointer to the last occurrence of the character in the string, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *string, int searchedChar)
{
	int	end;

	end = ft_strlen(string);
	searchedChar = (unsigned char) searchedChar;
	while (end >= 0)
	{
		if (string[end] == searchedChar)
			return ((char *)string + end);
		end--;
	}
	return (0);
}
