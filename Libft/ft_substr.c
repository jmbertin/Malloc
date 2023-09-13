#include "./libft.h"

/**
 * Returns the minimum of two size_t values.
 * @param	len		First size_t value.
 * @param	size_s	Second size_t value.
 * @return	Returns the smaller value between 'len' and 'size_s'.
 */
static size_t	ft_min(size_t len, size_t size_s)
{
	if (len > size_s)
		return (size_s);
	return (len);
}

/**
 * Extracts a substring from a string starting from 'start' and of length 'len'.
 * @param	s		Original string.
 * @param	start	Starting index for the substring.
 * @param	len		Length of the substring.
 * @return	Returns a new substring or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	size_s;

	i = 0;
	if (!s)
		return (0);
	size_s = ft_strlen(s);
	if ((len == 0 && start != 0) || start > size_s)
	{
		dest = (char *)malloc(sizeof(char));
		dest[i] = '\0';
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * (ft_min(len, size_s) + 1));
	if (dest == 0)
		return (0);
	while (i < len && i < size_s)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
