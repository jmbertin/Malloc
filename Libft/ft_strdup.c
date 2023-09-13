#include "./libft.h"

/**
 * Returns a pointer to a new string which is a duplicate of the string src.
 * @param	src	String to be duplicated.
 * @return	Returns a pointer to the duplicated string or NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, src, i + 1);
	return (dest);
}
