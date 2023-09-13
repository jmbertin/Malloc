#include "./libft.h"

/**
 * Determines if a character is part of a given charset.
 * @param	c		Character to be checked.
 * @param	set	String representing the charset.
 * @return	Returns 1 if 'c' is found in 'set', otherwise returns 0.
 */
static int	ft_is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Calculates the length of the destination string after trimming characters
 * present in 'set' from the start and end of 's1'.
 * @param	s1		Source string to be trimmed.
 * @param	set	Set of characters to be trimmed from 's1'.
 * @return	Returns the length of the trimmed string.
 */
static int	ft_dest_len(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	length;

	i = 0;
	length = ft_strlen(s1);
	end = length - 1;
	while (s1[i] && ft_is_charset(s1[i], set) == 1)
		i++;
	while (ft_is_charset(s1[end], set) == 1 && end > 0)
		end--;
	if (end < i)
		return (0);
	if (end == i)
		return (1);
	else
		return (end - i + 1);
}

/**
 * Trims the start and end of a string by removing characters present in set.
 * @param	s1	String to trim.
 * @param	set	Set of characters to remove.
 * @return	Returns the new trimmed string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		length;
	char	*trimmed;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	length = ft_dest_len(s1, set);
	trimmed = (char *)malloc(sizeof(char) * length + 1);
	if (trimmed == 0)
		return (NULL);
	while (ft_is_charset(s1[i], set) == 1)
		i++;
	while (s1[i] && length > 0)
	{
		trimmed[j] = s1[i];
		i++;
		j++;
		length--;
	}
	trimmed[j] = '\0';
	return (trimmed);
}
