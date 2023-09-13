#include "./libft.h"

/**
 * Copies a specified portion of one string into another.
 * This function copies 'size' characters starting from 'poz' index of 'src' to 'dest'.
 * @param	dest	Destination string where the content will be copied.
 * @param	src		Source string from which the content will be taken.
 * @param	size	Number of characters to copy from 'src'.
 * @param	poz		Starting position in 'src' from where to begin copying.
 */
static void	ft_strpcpy(char *dest, char *src, int size, int poz)
{
	int	i_src;
	int	i;

	i_src = poz;
	i = 0;
	while (i_src < poz + size)
	{
			dest[i] = src[i_src];
			i++;
			i_src++;
	}
	dest[size - 1] = '\0';
}

/**
 * Determines if a character is equal to a specified separator.
 * This function checks if 'c' is the same as the provided separator 'sep'.
 * @param	c		Character to check.
 * @param	sep	Separator character to compare with.
 * @return	Returns 1 if 'c' is equal to 'sep', otherwise returns 0.
 */
static int	ft_is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

/**
 * Counts the number of substrings in a string, delimited by a specified separator.
 * The function calculates how many times the string 'str' is divided by the separator 'sep'.
 * @param	str	String in which to count the substrings.
 * @param	sep	Separator character that divides the substrings in 'str'.
 * @return	Returns the number of substrings in 'str'.
 */
static int	ft_n_str(char *str, char sep)
{
	size_t	i;
	int		n_str;

	i = 0;
	n_str = 0;
	while (str[i])
	{
		while (ft_is_sep(str[i], sep) == 1 && str[i])
			i++;
		if (i < ft_strlen(str))
			n_str++;
		while (ft_is_sep(str[i], sep) == 0 && str[i])
			i++;
	}
	return (n_str);
}

/**
 * Executes the split operation on a string using a specified character.
 * Splits the string 's' into multiple substrings based on the delimiter 'c'.
 * The substrings are stored in the 'strs' array. Each substring is null-terminated.
 * @param	s		The string to be split.
 * @param	c		Delimiter character used to split the string.
 * @param	strs	Pointer to an array of strings where the split substrings will be stored.
 */
static void	ft_exec_split(char const *s, char c, char **strs)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && j < ft_n_str((char *)s, c))
	{
		while (ft_is_sep(s[i], c) == 1 && s[i])
			i++;
		while (ft_is_sep(s[i], c) == 0 && s[i])
		{
			i++;
			k++;
		}
		strs[j] = malloc(sizeof(char) * k + 1);
		ft_strpcpy(strs[j], (char *)s, k + 1, i - k);
		j++;
		k = 0;
	}
	strs[ft_n_str((char *)s, c)] = 0;
}

/**
 * Splits a string s using the character c as a delimiter.
 * @param	s	String to split.
 * @param	c	Delimiter character.
 * @return	Returns an array of new strings resulting from the split or NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_n_str((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	ft_exec_split(s, c, strs);
	return (strs);
}
