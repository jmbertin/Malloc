#include "./libft.h"

/**
 * Appends string src to the end of dst. Will append at most size - strlen(dst) - 1 characters.
 * @param	dest	Destination buffer.
 * @param	src	Source string.
 * @param	size	Size of the destination buffer.
 * @return	Returns the total length of the string that tried to create (initial length of dst + length of src).
 */
size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i_d;
	unsigned int	i_s;
	unsigned int	len_s;
	unsigned int	len_d;

	if (size == 0 && dest == 0)
		return (0);
	len_d = ft_strlen(dest);
	i_d = len_d;
	len_s = ft_strlen(src);
	i_s = len_s;
	i_s = 0;
	if (len_d == size || size < len_d)
		return (size + len_s);
	while (src[i_s] && (size - len_d - 1) > 0)
	{
		dest[i_d] = src[i_s];
		i_s++;
		i_d++;
		size--;
	}
	dest[i_d] = '\0';
	return (len_d + len_s);
}
