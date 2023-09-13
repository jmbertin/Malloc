#include "./libft.h"

/**
 * Copies n bytes from memory area src to memory area dest.
 * @param	dest	Pointer to the destination memory area.
 * @param	src	Pointer to the source memory area.
 * @param	n	Number of bytes to be copied.
 * @return	Returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		d[i] = s[i];
		n--;
		i++;
	}
	return (dest);
}
