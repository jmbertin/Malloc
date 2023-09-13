#include "./libft.h"

/**
 * Copies up to size - 1 characters from the string src to dst, null-terminating the result.
 * @param	dst	Destination buffer.
 * @param	src	Source string.
 * @param	size	Size of the destination buffer.
 * @return	Returns the total length of the string tried to create (length of src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	size_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (size_src);
}
